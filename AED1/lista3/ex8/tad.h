#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    float num;
    struct No *proximo;
} No;

typedef struct Pilha{
    No *topo;
} Pilha;

void Inicializar(Pilha *pilha);

int PilhaVazia(Pilha* pilha);

void Empilhar(Pilha* pilha, float num);

float Maior(Pilha *pilha);

float Menor(Pilha *pilha);

float Media(Pilha *pilha);