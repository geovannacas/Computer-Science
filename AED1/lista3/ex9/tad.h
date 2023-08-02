#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No *proximo;
} No;

typedef struct Pilha{
    No *topo;
} Pilha;

void Inicializar(Pilha *pilha);

int PilhaVazia(Pilha* pilha);

void Empilhar(Pilha* pilha, int num);

Pilha Inverter(Pilha *pilha);

void Imprime(Pilha *pilha);