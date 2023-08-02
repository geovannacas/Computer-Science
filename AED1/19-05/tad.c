#include "tad.h"

void criar_pilha(Pilha *pilha){
    pilha->topo = NULL;
}

bool esta_vazia(Pilha *pilha){
    return pilha->topo == NULL;
}

void empilhar(Pilha *pilha, int x){
    No *novo = (No*)malloc(sizeof(No));
    novo->item = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}
int desempilhar(Pilha *pilha){
    if(esta_vazia(pilha)){
        printf("Erro: Lista vazia\n");
        return 0;
    }
    No *remove = pilha->topo;
    int x = remove->item;
    pilha->topo = pilha->topo->prox;
    free(remove);

    return x;
}
int tamanho(Pilha *pilha){
    int i = 0;
    No *atual = pilha->topo;
    while (atual != 0)
    {
        i++;
        atual = atual->prox;
    }
    
    return i;
}

void imprime(Pilha *pilha){
    No *atual = pilha->topo;
    printf("Elementos da pilha:\n");

    while (atual != NULL)
    {   
        printf("%d\n", atual->item);
        atual = atual->prox;
    }
    
}