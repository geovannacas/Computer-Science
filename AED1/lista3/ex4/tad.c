#include "tad.h"

void Inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void Enfileirar(Fila *fila, int processo){
    No *novo = (No*)malloc(sizeof(No));

    novo->processo = processo;
    novo->tempo = 0;
    novo->proximo = NULL;

    if(FilaVazia(fila)){
        fila->inicio = novo;
        fila->fim = novo;
    } else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

void AddTempo(Fila* fila) {
    No* novo = fila->inicio;
    while (novo != NULL) {
        novo->tempo++;
        novo = novo->proximo;
    }
}

No *Desenfilerar(Fila *fila){
    if(FilaVazia(fila)){
        printf("Erro: fila está vazia\n");
        return NULL;
    }

    No* primeiro = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return primeiro;
}

void Imprime(Fila *fila){
    No *aux = fila->inicio;

    while(aux != NULL){

        printf("ID: %d - Tempo: %d\n", aux->processo, aux->tempo);

        aux = aux->proximo;
    }
    
}