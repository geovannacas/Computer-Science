
#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila{
    int num;
    struct NoFila *proximo;
} NoFila;

typedef struct{
    NoFila *inicio;
    NoFila *fim;
} Fila;

typedef struct NoPilha{
    int num;
    struct NoPilha *proximo;
} NoPilha;

typedef struct Pilha{
    NoPilha *topo;
} Pilha;

void InicializarPilha(Pilha *pilha);

int PilhaVazia(Pilha* pilha);

void Empilhar(Pilha* pilha, int num);

void Desempilhar(Pilha* pilha);

void ImprimePilha(Pilha *pilha);

void InicializarFila(Fila *fila);

int FilaVazia(Fila *fila);

void Enfileirar(Fila *fila, int num);

int Desenfilerar(Fila *fila);


