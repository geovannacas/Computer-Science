#include "tad.h"

void Inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->fim = fila->inicio;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void Enfileirar(Fila *fila, float valor, int prioridade){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = valor;
    novo->prioridade = prioridade;
    novo->proximo = NULL;

    if(FilaVazia(fila)){
        fila->inicio = novo;
        fila->fim = fila->inicio;
    } else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

Fila divPrioridade(Fila *fila, float p){
    No *aux = fila->inicio;
    Fila filadiv;
    Inicializar(&filadiv);

    while(aux !=  NULL){

        if(aux->prioridade >= p){
            Enfileirar(&filadiv, aux->valor, aux->prioridade);
        }

        aux = aux->proximo;
    }
    return filadiv;
}


Fila divPrioridadeResto(Fila *fila, float p){
    No *aux = fila->inicio;
    Fila filadiv;
    Inicializar(&filadiv);

    while(aux !=  NULL){

        if(aux->prioridade < p){
            Enfileirar(&filadiv, aux->valor, aux->prioridade);
        }

        aux = aux->proximo;
    }
    return filadiv;
}


void Imprime(Fila *fila){
    No *aux = fila->inicio;

    while(aux != NULL){

        printf("Valor: %.2f - Prioridade: %d\n", aux->valor, aux->prioridade);

        aux = aux->proximo;
    }
    
}