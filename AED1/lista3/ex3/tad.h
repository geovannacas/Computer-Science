#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    float valor;
    int prioridade;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
} Fila;

void Inicializar(Fila *fila);

int FilaVazia(Fila *fila);

void Enfileirar(Fila *fila, float valor, int prioridade);

Fila divPrioridade(Fila *fila, float p);
Fila divPrioridadeResto(Fila *fila, float p);

void Imprime(Fila *fila);


