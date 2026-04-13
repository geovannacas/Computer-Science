#ifndef TIPOS_H
#define TIPOS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {
    NO_PROGRAMA, NO_BLOCO, NO_DECL_VAR, NO_TIPO,

    NO_LEIA, NO_ESCREVA, NO_NOVALINHA,
    NO_SE, NO_ENQUANTO, NO_ATRIBUICAO,

    NO_OU, NO_E,
    NO_IGUAL, NO_DIFERENTE, NO_MAIOR, NO_MENOR, NO_MAIORIGUAL, NO_MENORIGUAL,

    NO_SOMA, NO_SUBTRACAO, NO_MULTIPLICACAO, NO_DIVISAO,
    NO_NEGACAO_ARITMETICA, NO_NEGACAO_LOGICA,

    NO_IDENTIFICADOR, NO_INTCONST, NO_CARCONST, NO_CADEIACARACTERES
} TipoNo;

typedef struct NoAST {
    TipoNo tipo;
    char*  lexema;
    int    linha;

    struct NoAST* filho1;
    struct NoAST* filho2;
    struct NoAST* filho3;

    struct NoAST* proximo;
} NoAST;

NoAST* criaNo(TipoNo tipo, const char* lexema, int linha,
              NoAST* f1, NoAST* f2, NoAST* f3);
void   adicionaIrmao(NoAST* lista, NoAST* irmao);
void   imprimeArvore(NoAST* raiz, int nivel);

#endif
