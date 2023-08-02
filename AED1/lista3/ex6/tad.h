#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int num;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
} Fila;

void Inicializar(Fila *fila);

int FilaVazia(Fila *fila);

void Enfileirar(Fila *fila, int num);

void SomaFilas(Fila *fila1, Fila *fila2, Fila *fila3);

void Imprime(Fila *fila);