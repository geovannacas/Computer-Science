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

Fila Inverter(Fila *fila){
    Fila filainvertida;
    Inicializar(&filainvertida);
    for (int i = fila->fim; i >= fila->inicio; i--) {
        Enfilerar(&filainvertida, fila->fila[i]);
    }

    return filainvertida;
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