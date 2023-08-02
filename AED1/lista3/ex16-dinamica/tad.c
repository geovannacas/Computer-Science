#include "tad.h"

void Inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void Enfilerar(Fila *fila, int num){
    No *novo = (No*)malloc(sizeof(No));

    novo->num = num;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if(FilaVazia(fila)){
        fila->inicio = novo;
        fila->fim = novo;
    } else{
        novo->anterior = fila->fim;
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

void RemoverNeg(Fila *fila){
   No *aux = fila->inicio;

   while(aux !=  NULL){
        if(aux->num < 0){
            if(aux->anterior == NULL){
                fila->inicio = aux->proximo;
            } else if(aux->proximo == NULL){
                fila->fim = aux->anterior;
                aux->anterior->proximo = NULL;
            } else{
                aux->proximo->anterior = aux->anterior;
                aux->anterior->proximo = aux->proximo;
            }
        }

        aux = aux->proximo;
   }

   free(aux);
}

void Imprime(Fila *fila){
    No *aux = fila->inicio;

    printf("Conteúdo da fila:\n");
    while(aux != NULL){
        printf("%d\n", aux->num);
        aux = aux->proximo;
    }

}