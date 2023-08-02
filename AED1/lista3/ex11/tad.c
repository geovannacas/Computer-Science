#include "tad.h"

// Fila

void InicializarFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void Enfileirar(Fila *fila, int num){
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));

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

int Desenfilerar(Fila *fila){
    if(FilaVazia(fila)){
        printf("Erro: fila está vazia\n");
        return;
    }

    int primeiro = fila->inicio->num;
    NoFila* temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(temp);

    return primeiro;
}

// Pilha

void InicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int PilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void Empilhar(Pilha* pilha, int num) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->num = num;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void Desempilhar(Pilha* pilha) {
    if (PilhaVazia(pilha)) {
        printf("Erro: a pilha está vazia e não é possível remover elementos.\n");
        return;
    }

    NoPilha* topoinicial = pilha->topo;
    pilha->topo = topoinicial->proximo;
    free(topoinicial);
}


void ImprimePilha(Pilha *pilha){
    NoPilha *aux = pilha->topo;

    printf("Conteúdo da pilha:\n");

    while (aux != NULL)
    {
        printf("Número: %d\n", aux->num);
        aux = aux->proximo;
    }

}