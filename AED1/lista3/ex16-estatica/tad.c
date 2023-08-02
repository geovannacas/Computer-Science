#include "tad.h"

void Inicializar(Fila *fila){
    fila->fim = -1;
    fila->inicio = -1;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == -1);
}

int FilaCheia(Fila *fila) {
    return (fila->fim == MAX_SIZE - 1);
}

void Enfilerar(Fila *fila, int num){
    if(FilaCheia(fila)){
        printf("A fila está cheia.\n");
    } else{
        if(FilaVazia(fila)){
            fila->inicio = 0;
        }
        fila->fim++;
        fila->fila[fila->fim] = num;
    }
}

void RemoverNeg(Fila *fila){
    int j = fila->inicio;
    for (int i = fila->inicio; i <= fila->fim; i++) {
        if(fila->fila[i] >= 0){
            fila->fila[j] = fila->fila[i];
            j++;
        }
    }

    fila->fim = j-1;
}

void Imprime(Fila *fila){
    if (FilaVazia(fila)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Conteúdo na fila: ");
        for (int i = fila->inicio; i <= fila->fim; i++) {
            printf("%d ", fila->fila[i]);
        }
        printf("\n");
    }
}