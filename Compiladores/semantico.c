#include "semantico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static PilhaTabelas* pilha_sem = NULL;

static void erro_semantico(const char* msg, int linha) {
    fprintf(stderr, "ERRO: %s na linha %d\n", msg, linha);
    exit(1);
}

/* Declaracoes antecipadas para recursao mutua */
static void         analisa_bloco(NoAST* no);
static void         analisa_comando(NoAST* no);
static const char*  analisa_expr(NoAST* no);

/* Insere todas as declaracoes do bloco na tabela de simbolos atual */
static void processa_decl(NoAST* no) {
    while (no != NULL) {
        if (no->tipo == NO_DECL_VAR) {
            const char* nome = no->lexema;
            const char* tipo = (no->filho1 && no->filho1->tipo == NO_TIPO)
                               ? no->filho1->lexema : "?";
            if (!insereTabela(pilha_sem, nome, tipo, no->linha)) {
                char msg[256];
                snprintf(msg, sizeof(msg), "VARIAVEL JA DECLARADA: %s", nome);
                erro_semantico(msg, no->linha);
            }
        }
        no = no->proximo;
    }
}

static void analisa_bloco(NoAST* no) {
    if (!no || no->tipo != NO_BLOCO) return;

    int tem_decl = (no->filho1 != NULL);

    if (tem_decl) {
        criaEscopo(pilha_sem);
        processa_decl(no->filho1);
    }

    NoAST* cmd = no->filho2;
    while (cmd) {
        analisa_comando(cmd);
        cmd = cmd->proximo;
    }

    if (tem_decl) removeEscopo(pilha_sem);
}

static void analisa_comando(NoAST* no) {
    if (!no) return;

    switch (no->tipo) {
        case NO_BLOCO:
            analisa_bloco(no);
            break;

        case NO_LEIA: {
            NoAST* id = no->filho1; /* NO_IDENTIFICADOR */
            if (!pesquisaTabela(pilha_sem, id->lexema)) {
                char msg[256];
                snprintf(msg, sizeof(msg), "VARIAVEL NAO DECLARADA: %s", id->lexema);
                erro_semantico(msg, id->linha);
            }
            break;
        }

        case NO_ESCREVA:
            analisa_expr(no->filho1);
            break;

        case NO_NOVALINHA:
            break;

        case NO_SE:
            analisa_expr(no->filho1);          /* condicao */
            analisa_comando(no->filho2);       /* entao */
            if (no->filho3) analisa_comando(no->filho3); /* senao */
            break;

        case NO_ENQUANTO:
            analisa_expr(no->filho1);          /* condicao */
            analisa_comando(no->filho2);       /* corpo */
            break;

        default:
            analisa_expr(no); /* comando de expressao (atribuicao, etc.) */
            break;
    }
}

static const char* analisa_expr(NoAST* no) {
    if (!no) return "?";

    switch (no->tipo) {
        case NO_INTCONST:
            return "int";

        case NO_CARCONST:
            return "car";

        case NO_CADEIACARACTERES:
            return "str"; /* tipo especial apenas para escreva */

        case NO_IDENTIFICADOR: {
            Simbolo* s = pesquisaTabela(pilha_sem, no->lexema);
            if (!s) {
                char msg[256];
                snprintf(msg, sizeof(msg), "VARIAVEL NAO DECLARADA: %s", no->lexema);
                erro_semantico(msg, no->linha);
            }
            return s->tipo;
        }

        case NO_ATRIBUICAO: {
            NoAST* id = no->filho1; /* NO_IDENTIFICADOR */
            Simbolo* s = pesquisaTabela(pilha_sem, id->lexema);
            if (!s) {
                char msg[256];
                snprintf(msg, sizeof(msg), "VARIAVEL NAO DECLARADA: %s", id->lexema);
                erro_semantico(msg, id->linha);
            }
            const char* tipo_dir = analisa_expr(no->filho2);
            if (strcmp(s->tipo, tipo_dir) != 0) {
                char msg[256];
                snprintf(msg, sizeof(msg),
                         "TIPOS INCOMPATIVEIS NA ATRIBUICAO DA VARIAVEL %s", id->lexema);
                erro_semantico(msg, no->linha);
            }
            return s->tipo;
        }

        case NO_SOMA:
        case NO_SUBTRACAO:
        case NO_MULTIPLICACAO:
        case NO_DIVISAO: {
            const char* te = analisa_expr(no->filho1);
            const char* td = analisa_expr(no->filho2);
            if (strcmp(te, "int") != 0 || strcmp(td, "int") != 0) {
                erro_semantico("OPERACAO ARITMETICA REQUER TIPO INT", no->linha);
            }
            return "int";
        }

        case NO_NEGACAO_ARITMETICA: {
            const char* t = analisa_expr(no->filho1);
            if (strcmp(t, "int") != 0) {
                erro_semantico("NEGACAO ARITMETICA REQUER TIPO INT", no->linha);
            }
            return "int";
        }

        case NO_NEGACAO_LOGICA:
            analisa_expr(no->filho1);
            return "int";

        case NO_IGUAL:
        case NO_DIFERENTE:
        case NO_MAIOR:
        case NO_MENOR:
        case NO_MAIORIGUAL:
        case NO_MENORIGUAL: {
            const char* te = analisa_expr(no->filho1);
            const char* td = analisa_expr(no->filho2);
            if (strcmp(te, td) != 0) {
                erro_semantico("OPERACAO RELACIONAL COM TIPOS DIFERENTES", no->linha);
            }
            return "int";
        }

        case NO_OU:
        case NO_E: {
            const char* te = analisa_expr(no->filho1);
            const char* td = analisa_expr(no->filho2);
            if (strcmp(te, "int") != 0 || strcmp(td, "int") != 0) {
                erro_semantico("OPERADOR LOGICO REQUER TIPO INT", no->linha);
            }
            return "int";
        }

        default:
            return "?";
    }
}

void analisaSemantico(NoAST* raiz) {
    pilha_sem = iniciaTabela();
    analisa_bloco(raiz);
    liberaTabela(pilha_sem);
    pilha_sem = NULL;
}
