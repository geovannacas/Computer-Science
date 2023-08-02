#include "tad.h"

void Inicializar(Pilha* pilha) {
    pilha->topo = NULL;
}

int PilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void Empilhar(Pilha* pilha, int num) {
    No* novo = (No*)malloc(sizeof(No));
    novo->num = num;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int Desempilhar(Pilha* pilha) {
    if (PilhaVazia(pilha)) {
        printf("Erro: a pilha está vazia\n");
        return 0;
    }

    No* topoinicial = pilha->topo;
    int numretirado = topoinicial->num;
    pilha->topo = topoinicial->proximo;
    free(topoinicial);

    return numretirado;
}