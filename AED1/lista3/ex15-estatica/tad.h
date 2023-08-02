#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int fila[MAX_SIZE];
    int inicio, fim;
} Fila;

void Inicializar(Fila *fila);

int FilaVazia(Fila *fila);

int FilaCheia(Fila *fila);

void Enfilerar(Fila *fila, int num);

Fila Inverter(Fila *fila);

void Imprime(Fila *fila);
