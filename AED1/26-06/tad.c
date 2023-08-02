#include "tad.h"

void Inicializar(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

int ListaVazia(Lista *lista){
    return (lista->inicio == NULL);
}

void InserirComeco(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = valor;

    if(ListaVazia(lista)){
        novo->proximo = novo;
        lista->inicio = novo;
        lista->fim = novo;
    } else{
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->fim->proximo = lista->inicio;
    }
}
void InserirFim(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = valor;

    if(ListaVazia(lista)){
        novo->proximo = novo;
        lista->inicio = novo;
        lista->fim = novo;
    } else{
        novo->proximo = lista->inicio;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
}

void Imprime(Lista *lista){
    No *aux = lista->inicio;

    printf("Lista - Elementos:\n");
    do{
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }while (aux != lista->inicio);
    printf("\n");
}

int Buscar(Lista *lista, int valor){
    No *aux = lista->inicio;

    do{
        if(aux->valor == valor){
            return 1;
        }
        aux = aux->proximo;
    }while (aux != lista->inicio);

    return 0;
}
int Qtd(Lista *lista){
    No *aux = lista->inicio;
    int qtd = 0;

    do{
        qtd++;
        aux = aux->proximo;
    } while (aux != lista->inicio);

    return qtd;
}