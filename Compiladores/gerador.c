#include "gerador.h"
#include "tabsim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Constantes de string no segmento .data ---------- */

typedef struct StrConst {
    int           id;
    char*         valor;
    struct StrConst* prox;
} StrConst;

static StrConst* str_cabeca = NULL;
static int       str_count  = 0;
static int       label_count = 0;
static PilhaTabelas* pilha_gen = NULL;

static int novo_label(void) { return label_count++; }

static int get_str_id(const char* valor) {
    StrConst* sc = str_cabeca;
    while (sc) {
        if (strcmp(sc->valor, valor) == 0) return sc->id;
        sc = sc->prox;
    }
    StrConst* novo = (StrConst*) malloc(sizeof(StrConst));
    novo->id    = str_count++;
    novo->valor = strdup(valor);
    novo->prox  = str_cabeca;
    str_cabeca  = novo;
    return novo->id;
}

/* Pre-varre a AST coletando todas as strings literais */
static void coleta_strings(NoAST* no) {
    if (!no) return;
    if (no->tipo == NO_CADEIACARACTERES && no->lexema)
        get_str_id(no->lexema);
    coleta_strings(no->filho1);
    coleta_strings(no->filho2);
    coleta_strings(no->filho3);
    coleta_strings(no->proximo);
}

/* ---------- Conversao de CARCONST para valor ASCII ---------- */

static int carconst_valor(const char* lexema) {
    /* lexema: 'c'  ou  '\e'  (inclui aspas simples) */
    if (lexema[1] == '\\') {
        switch (lexema[2]) {
            case 'n':  return 10;
            case 't':  return 9;
            case '\\': return 92;
            case '\'': return 39;
            case '0':  return 0;
            default:   return (int)(unsigned char)lexema[2];
        }
    }
    return (int)(unsigned char)lexema[1];
}

/* ---------- Declaracoes antecipadas ---------- */

static void         gera_bloco(NoAST* no);
static void         gera_comando(NoAST* no);
static const char*  gera_expr(NoAST* no);

/* ---------- Geracao de expressoes ----------
 * Resultado da expressao fica em $t0.
 * Retorna o tipo ("int" ou "car").
 */
static const char* gera_expr(NoAST* no) {
    if (!no) return "?";

    switch (no->tipo) {

        /* ----- Literais ----- */
        case NO_INTCONST:
            printf("    li $t0, %s\n", no->lexema);
            return "int";

        case NO_CARCONST:
            printf("    li $t0, %d\n", carconst_valor(no->lexema));
            return "car";

        /* ----- Variavel ----- */
        case NO_IDENTIFICADOR: {
            Simbolo* s = pesquisaTabela(pilha_gen, no->lexema);
            printf("    lw $t0, %d($fp)\n", s->offset);
            return s->tipo;
        }

        /* ----- Atribuicao ----- */
        case NO_ATRIBUICAO: {
            const char* tipo = gera_expr(no->filho2); /* avalia lado direito */
            Simbolo* s = pesquisaTabela(pilha_gen, no->filho1->lexema);
            printf("    sw $t0, %d($fp)\n", s->offset);
            return tipo;
        }

/* ---------- Macro auxiliar para operacoes binarias ----------
 * Avalia esquerda -> push -> avalia direita -> pop em $t1.
 * Apos a macro: $t1 = esquerda, $t0 = direita.
 */
#define AVALIA_BINARIO(esq, dir) \
    gera_expr(esq); \
    printf("    addiu $sp, $sp, -4\n"); \
    printf("    sw $t0, 0($sp)\n"); \
    gera_expr(dir); \
    printf("    lw $t1, 0($sp)\n"); \
    printf("    addiu $sp, $sp, 4\n")

        /* ----- Aritmetica ----- */
        case NO_SOMA:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    add $t0, $t1, $t0\n");
            return "int";

        case NO_SUBTRACAO:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    sub $t0, $t1, $t0\n");
            return "int";

        case NO_MULTIPLICACAO:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    mul $t0, $t1, $t0\n");
            return "int";

        case NO_DIVISAO:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    div $t1, $t0\n");   /* $t1 / $t0, quociente em LO */
            printf("    mflo $t0\n");
            return "int";

        case NO_NEGACAO_ARITMETICA:
            gera_expr(no->filho1);
            printf("    sub $t0, $zero, $t0\n");
            return "int";

        /* ----- Logica ----- */
        case NO_NEGACAO_LOGICA:
            gera_expr(no->filho1);
            printf("    seq $t0, $t0, $zero\n"); /* 1 se zero, 0 caso contrario */
            return "int";

        case NO_OU:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    sne $t1, $t1, $zero\n");
            printf("    sne $t0, $t0, $zero\n");
            printf("    or  $t0, $t1, $t0\n");
            return "int";

        case NO_E:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    sne $t1, $t1, $zero\n");
            printf("    sne $t0, $t0, $zero\n");
            printf("    and $t0, $t1, $t0\n");
            return "int";

        /* ----- Comparacao ----- */
        case NO_IGUAL:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    seq $t0, $t1, $t0\n");
            return "int";

        case NO_DIFERENTE:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    sne $t0, $t1, $t0\n");
            return "int";

        case NO_MAIOR:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    sgt $t0, $t1, $t0\n");
            return "int";

        case NO_MENOR:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    slt $t0, $t1, $t0\n");
            return "int";

        case NO_MAIORIGUAL:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    sge $t0, $t1, $t0\n");
            return "int";

        case NO_MENORIGUAL:
            AVALIA_BINARIO(no->filho1, no->filho2);
            printf("    sle $t0, $t1, $t0\n");
            return "int";

#undef AVALIA_BINARIO

        default:
            return "?";
    }
}

/* ---------- Geracao de comandos ---------- */

static void gera_comando(NoAST* no) {
    if (!no) return;

    switch (no->tipo) {

        case NO_BLOCO:
            gera_bloco(no);
            break;

        /* leia id */
        case NO_LEIA: {
            NoAST* id = no->filho1; /* NO_IDENTIFICADOR */
            Simbolo* s = pesquisaTabela(pilha_gen, id->lexema);
            if (strcmp(s->tipo, "int") == 0) {
                printf("    li $v0, 5\n");    /* read_int */
            } else {
                printf("    li $v0, 12\n");   /* read_char */
            }
            printf("    syscall\n");
            printf("    sw $v0, %d($fp)\n", s->offset);
            break;
        }

        /* escreva expr | escreva string */
        case NO_ESCREVA: {
            NoAST* expr = no->filho1;
            if (expr->tipo == NO_CADEIACARACTERES) {
                int sid = get_str_id(expr->lexema);
                printf("    la $a0, __str_%d\n", sid);
                printf("    li $v0, 4\n");    /* print_string */
                printf("    syscall\n");
            } else {
                const char* tipo = gera_expr(expr);
                printf("    move $a0, $t0\n");
                if (strcmp(tipo, "car") == 0) {
                    printf("    li $v0, 11\n"); /* print_char */
                } else {
                    printf("    li $v0, 1\n");  /* print_int */
                }
                printf("    syscall\n");
            }
            break;
        }

        /* novalinha */
        case NO_NOVALINHA:
            printf("    li $v0, 11\n");   /* print_char */
            printf("    li $a0, 10\n");   /* '\n' */
            printf("    syscall\n");
            break;

        /* se (cond) entao cmd [senao cmd] fimse */
        case NO_SE: {
            int lbl = novo_label();
            gera_expr(no->filho1); /* condicao -> $t0 */
            if (no->filho3) {
                printf("    beq $t0, $zero, __senao_%d\n", lbl);
                gera_comando(no->filho2);
                printf("    j __fimse_%d\n", lbl);
                printf("__senao_%d:\n", lbl);
                gera_comando(no->filho3);
                printf("__fimse_%d:\n", lbl);
            } else {
                printf("    beq $t0, $zero, __fimse_%d\n", lbl);
                gera_comando(no->filho2);
                printf("__fimse_%d:\n", lbl);
            }
            break;
        }

        /* enquanto (cond) cmd */
        case NO_ENQUANTO: {
            int lbl = novo_label();
            printf("__enquanto_cond_%d:\n", lbl);
            gera_expr(no->filho1); /* condicao -> $t0 */
            printf("    beq $t0, $zero, __enquanto_fim_%d\n", lbl);
            gera_comando(no->filho2);
            printf("    j __enquanto_cond_%d\n", lbl);
            printf("__enquanto_fim_%d:\n", lbl);
            break;
        }

        default:
            /* Comando de expressao (atribuicao, etc.) */
            gera_expr(no);
            break;
    }
}

/* ---------- Geracao de blocos ---------- */

static void gera_bloco(NoAST* no) {
    if (!no || no->tipo != NO_BLOCO) return;

    int tem_decl = (no->filho1 != NULL);
    int frame_bytes = 0;

    if (tem_decl) {
        criaEscopo(pilha_gen);

        /* Insere variaveis na tabela e calcula espaco necessario */
        NoAST* decl = no->filho1;
        while (decl) {
            if (decl->tipo == NO_DECL_VAR) {
                const char* tipo = (decl->filho1 && decl->filho1->tipo == NO_TIPO)
                                   ? decl->filho1->lexema : "int";
                insereTabela(pilha_gen, decl->lexema, tipo, decl->linha);
            }
            decl = decl->proximo;
        }

        frame_bytes = pilha_gen->topo->num_vars * 4;
        if (frame_bytes > 0)
            printf("    addiu $sp, $sp, -%d\n", frame_bytes);
    }

    /* Gera codigo para a lista de comandos */
    NoAST* cmd = no->filho2;
    while (cmd) {
        gera_comando(cmd);
        cmd = cmd->proximo;
    }

    if (tem_decl) {
        int size = removeEscopo(pilha_gen);
        if (size > 0)
            printf("    addiu $sp, $sp, %d\n", size);
    }
}

/* ---------- Funcao principal de geracao ---------- */

void geraCodigoMIPS(NoAST* raiz) {
    /* Coleta constantes de string antes de gerar o codigo */
    str_cabeca  = NULL;
    str_count   = 0;
    label_count = 0;
    coleta_strings(raiz);

    /* Segmento de dados */
    printf(".data\n");
    /* Emite strings em ordem de ID crescente */
    for (int i = 0; i < str_count; i++) {
        StrConst* sc = str_cabeca;
        while (sc) {
            if (sc->id == i)
                printf("__str_%d: .asciiz \"%s\"\n", sc->id, sc->valor);
            sc = sc->prox;
        }
    }
    printf("\n");

    /* Segmento de texto */
    printf(".text\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    move $fp, $sp\n"); /* $fp fixo para todo o programa */

    /* Gera codigo do bloco principal */
    pilha_gen = iniciaTabela();
    gera_bloco(raiz);
    liberaTabela(pilha_gen);
    pilha_gen = NULL;

    /* Encerramento */
    printf("    li $v0, 10\n");
    printf("    syscall\n");

    /* Libera lista de strings */
    StrConst* sc = str_cabeca;
    while (sc) {
        StrConst* prox = sc->prox;
        free(sc->valor);
        free(sc);
        sc = prox;
    }
    str_cabeca = NULL;
}
