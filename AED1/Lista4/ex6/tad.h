#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[50];
    struct No *proximo;
} No;

typedef struct Fila{
    No *inicio;
    No *final;
} Fila;

void Inicializar(Fila *fila);
int FilaVazia(Fila *fila);
void Inserir(Fila *fila, char nome[50]);
void OrdenarPorSelecao(Fila *fila);
void OrdenarPorInsercao(Fila *fila);
void ImprimirFila(Fila* fila) ;
void LiberarFila(Fila* fila);