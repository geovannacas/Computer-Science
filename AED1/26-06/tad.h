#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
} Lista;

void Inicializar(Lista *lista);
int ListaVazia(Lista *lista);
void InserirFim(Lista *lista, int valor);
void InserirComeco(Lista *lista, int valor);
int Buscar(Lista *lista, int valor);
int Qtd(Lista *lista);
void Imprime(Lista *lista);