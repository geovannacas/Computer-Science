#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{
    int codigo;
    char nome[50];
    int quantidade;
} Produto;

typedef struct No
{
    Produto produto;
    struct No *proximo;
} No;

typedef struct Pilha
{
    No *topo;
} Pilha;

void criar_pilha(Pilha *pilha);
void empilha(Pilha *pilha, Produto p);
struct Produto desempilha(Pilha *pilha);
int isEmpty(Pilha *pilha);

void imprime_topo(Pilha *pilha);
int qtd_estoque(Pilha *pilha);

