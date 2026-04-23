#ifndef TABSIM_H
#define TABSIM_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define HASH_TABSIM 31

typedef struct Simbolo {
    char*          nome;
    char*          tipo;    /* "int" ou "car" */
    int            linha;
    int            offset;  /* offset em bytes a partir de $fp (negativo) */
    struct Simbolo* prox;
} Simbolo;

typedef struct TabelaSimbolos {
    Simbolo*               buckets[HASH_TABSIM];
    int                    num_vars;
    int                    offset_base;   /* valor de offset_corrente antes do criaEscopo */
    struct TabelaSimbolos* anterior;
} TabelaSimbolos;

typedef struct {
    TabelaSimbolos* topo;
    int             offset_corrente; /* proximo offset disponivel (decresce de 4 em 4) */
} PilhaTabelas;

PilhaTabelas* iniciaTabela(void);
void          criaEscopo(PilhaTabelas* pilha);
int           insereTabela(PilhaTabelas* pilha, const char* nome,
                           const char* tipo, int linha);
Simbolo*      pesquisaTabela(PilhaTabelas* pilha, const char* nome);
Simbolo*      pesquisaEscopoAtual(PilhaTabelas* pilha, const char* nome);
int           removeEscopo(PilhaTabelas* pilha); /* retorna bytes alocados no escopo */
void          liberaTabela(PilhaTabelas* pilha);

#endif
