#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Pilha {
    int pilha[MAX_SIZE];
    int topo;
} Pilha;

void Inicializar(Pilha* pilha);

int PilhaVazia(Pilha* pilha);

int PilhaCheia(Pilha* pilha);

void Empilhar(Pilha* pilha, int num);

Pilha Inverter(Pilha *pilha);

void Imprime(Pilha* pilha);