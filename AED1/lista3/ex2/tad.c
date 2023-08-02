#include "tad.h"

void Inicializar(Fila *fila){
    fila->fim = -1;
    fila->inicio = 0;
}

int FilaVazia(Fila *fila){
    return (fila->fim == -1);
}

int FilaCheia(Fila *fila) {
    return (fila->fim == MAX_SIZE-1);
}


void Desenfileirar(Fila* fila) {
    if (FilaVazia(fila)) {
        printf("Erro: fila vazia\n");
        return;
    }
    
    int i;
    for (i = fila->inicio; i < fila->fim; i++) {
        fila->fila[i] = fila->fila[i+1];
    }
    fila->fim--;
}

void Enfileirar(Fila* fila, int valor) {
    if (FilaCheia(fila)) {
        int i;
        for (i = fila->inicio; i < fila->fim; i++) {
            fila->fila[i] = fila->fila[i+1];
        }
        fila->fim--;
    }
    
    fila->fim++;
    fila->fila[fila->fim] = valor;
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