#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int pilha[MAX];
    int topo;
} Pilha;

void criar_pilha(Pilha *pilha);
bool esta_vazia(Pilha *pilha);
void empilhar(Pilha *pilha, int x);
int desempilhar(Pilha *pilha);
int tamanho(Pilha *pilha);
void imprime(Pilha *pilha);