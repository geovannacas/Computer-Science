#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 

typedef struct {
    char nome[50];
} Item;

typedef struct {
    Item elementos[MAX_SIZE];
    int indice;
} Lista;

void Inicializar(Lista *lista);
int ListaVazia(Lista *lista);
int ListaCheia(Lista *lista);
void Inserir(Lista *lista, char nome[50]);
void OrdenarPorSelecao(Lista *lista);
void OrdenarPorInsercao(Lista *lista);
void ImprimirLista(Lista* lista);