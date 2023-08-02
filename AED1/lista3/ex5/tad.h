#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[50];
    int capacidade;
    char tipo[50];
} Aviao;

typedef struct No{
    Aviao aviao;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
} Fila;

void Inicializar(Fila *fila);

int FilaVazia(Fila *fila);

void AdicionarAviao(Fila *fila, int id, char nome[50], int capacidade, char tipo[50]);

No *AutorizarDecolagem(Fila *fila);

int NumeroAviao(Fila *fila);

void ListarFila(Fila *fila);

void ImprimePrimeiro(Fila *fila);
