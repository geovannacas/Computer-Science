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

void Desenfileirar(Fila* fila);

void Enfileirar(Fila* fila, int valor);

void Imprime(Fila *fila);