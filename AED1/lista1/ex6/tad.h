#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int Item;
    struct No *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Lista;

No *Aloca();

Lista *Inicializar();

void Insere(int x, int pos, Lista *lista);

void Imprime(Lista *lista);

int Tamanho(Lista *lista);

Lista *Vetor(int vetor[], int tamanho);