#include "tad.h"

void Inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void Enfileirar(Fila *fila, int num){
    No *novo = (No*)malloc(sizeof(No));

    novo->num = num;
    novo->proximo = NULL;

    if(FilaVazia(fila)){
        fila->inicio = novo;
        fila->fim = novo;
    } else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

void SomaFilas(Fila *fila1, Fila *fila2, Fila *fila3){
    No *aux1 = fila1->inicio;
    No *aux2 = fila2->inicio;

    while(aux1 != NULL && aux2 != NULL){
        if(aux1->num < aux2->num){
            Enfileirar(fila3, aux1->num);
            aux1 = aux1->proximo;
        } else{
            Enfileirar(fila3, aux2->num);
            aux2 = aux2->proximo;
        }
    }

    while(aux1 != NULL){
        Enfileirar(fila3, aux1->num);
        aux1 = aux1->proximo;
    }

    while(aux2 != NULL){
        Enfileirar(fila3, aux2->num);
        aux2 = aux2->proximo;
    }

}

void Imprime(Fila *fila){
    No *aux = fila->inicio;

    while(aux != NULL){

        printf("Valor: %d\n", aux->num);

        aux = aux->proximo;
    }
    
}