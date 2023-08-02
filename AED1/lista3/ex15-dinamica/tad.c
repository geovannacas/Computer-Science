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

Fila Inverter(Fila* fila) {
    Fila filainvertida;
    Inicializar(&filainvertida);

    No* atual = fila->fim;

    while (atual != NULL) {
        Enfilerar(&filainvertida, atual->num);
        atual = atual->anterior;
    }

    return filainvertida;
}

void Imprime(Fila *fila){
    No *aux = fila->inicio;

    printf("Conteúdo da fila:\n");
    while(aux != NULL){
        printf("%d\n", aux->num);
        aux = aux->proximo;
    }

}
