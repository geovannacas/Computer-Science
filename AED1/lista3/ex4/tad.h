
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int tempo;
    int processo;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
} Fila;

void Inicializar(Fila *fila);

int FilaVazia(Fila *fila);

void AddTempo(Fila* fila);

void Enfileirar(Fila *fila, int processo);

No *Desenfilerar(Fila *fila);

void Imprime(Fila *fila);