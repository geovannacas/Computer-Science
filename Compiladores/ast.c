#include "tipos.h"

NoAST* criaNo(TipoNo tipo, const char* lexema, int linha,
              NoAST* f1, NoAST* f2, NoAST* f3) {
    NoAST* no = (NoAST*) malloc(sizeof(NoAST));
    if (no == NULL) {
        fprintf(stderr, "ERRO: Falha de alocacao de memoria para a AST\n");
        exit(1);
    }
    no->tipo    = tipo;
    no->lexema  = (lexema != NULL) ? strdup(lexema) : NULL;
    no->linha   = linha;
    no->filho1  = f1;
    no->filho2  = f2;
    no->filho3  = f3;
    no->proximo = NULL;
    return no;
}

void adicionaIrmao(NoAST* lista, NoAST* irmao) {
    if (lista == NULL || irmao == NULL) return;
    NoAST* atual = lista;
    while (atual->proximo != NULL)
        atual = atual->proximo;
    atual->proximo = irmao;
}

static const char* tipoNoParaString(TipoNo tipo) {
    switch (tipo) {
        case NO_PROGRAMA:           return "Programa";
        case NO_BLOCO:              return "Bloco";
        case NO_DECL_VAR:           return "DeclVar";
        case NO_TIPO:               return "Tipo";
        case NO_LEIA:               return "Leia";
        case NO_ESCREVA:            return "Escreva";
        case NO_NOVALINHA:          return "NovaLinha";
        case NO_SE:                 return "Se";
        case NO_ENQUANTO:           return "Enquanto";
        case NO_ATRIBUICAO:         return "Atribuicao (=)";
        case NO_SOMA:               return "Soma (+)";
        case NO_SUBTRACAO:          return "Subtracao (-)";
        case NO_MULTIPLICACAO:      return "Multiplicacao (*)";
        case NO_DIVISAO:            return "Divisao (/)";
        case NO_IGUAL:              return "Igual (==)";
        case NO_DIFERENTE:          return "Diferente (!=)";
        case NO_MAIOR:              return "Maior (>)";
        case NO_MENOR:              return "Menor (<)";
        case NO_MAIORIGUAL:         return "Maior Igual (>=)";
        case NO_MENORIGUAL:         return "Menor Igual (<=)";
        case NO_OU:                 return "Operador OU (||)";
        case NO_E:                  return "Operador E (&)";
        case NO_NEGACAO_ARITMETICA: return "Negacao Aritmetica (-)";
        case NO_NEGACAO_LOGICA:     return "Negacao (!)";
        case NO_IDENTIFICADOR:      return "ID";
        case NO_INTCONST:           return "IntConst";
        case NO_CARCONST:           return "CarConst";
        case NO_CADEIACARACTERES:   return "String";
        default:                    return "Desconhecido";
    }
}

void imprimeArvore(NoAST* raiz, int nivel) {
    if (raiz == NULL) return;

    for (int i = 0; i < nivel; i++)
        printf("  | ");

    printf("%s", tipoNoParaString(raiz->tipo));
    if (raiz->lexema != NULL)
        printf(" [%s]", raiz->lexema);
    printf(" (Linha: %d)\n", raiz->linha);

    imprimeArvore(raiz->filho1, nivel + 1);
    imprimeArvore(raiz->filho2, nivel + 1);
    imprimeArvore(raiz->filho3, nivel + 1);

    imprimeArvore(raiz->proximo, nivel);
}
