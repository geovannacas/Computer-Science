#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct{
    No *inicio;
    No *fim;
} Fila;

void Inicializar(Fila *fila);

int FilaVazia(Fila *fila);

void Enfilerar(Fila *fila, int num);

void RemoverNeg(Fila *fila);

void Imprime(Fila *fila);