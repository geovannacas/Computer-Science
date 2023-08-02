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

Pilha Copiar(Pilha *pilha){
    Pilha pilhaaux;
    Inicializar(&pilhaaux);

    No *aux = pilha->topo;

    while (aux != NULL)
    {
        int num = aux->num;
        Empilhar(&pilhaaux, num);
        aux = aux->proximo;
    }

    Pilha pilha2;
    Inicializar(&pilha2);

    No *aux2 = pilhaaux.topo;

    while (aux2 != NULL)
    {
        int num = aux2->num;
        Empilhar(&pilha2, num);
        aux2 = aux2->proximo;
    }

    return pilha2;
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