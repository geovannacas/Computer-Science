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

Pilha Inverter(Pilha *pilha){
    No *aux = pilha->topo;
    Pilha pilhaInvertida;
    Inicializar(&pilhaInvertida);

    while (aux != NULL)
    {
        Empilhar(&pilhaInvertida, aux->num);
        aux = aux->proximo;
    }

    return pilhaInvertida;
}

void Imprime(Pilha *pilha){
    No *aux = pilha->topo;

    printf("Pilha:\n");

    while (aux != NULL)
    {
        printf("%d\n", aux->num);
        aux = aux->proximo;
    }

}