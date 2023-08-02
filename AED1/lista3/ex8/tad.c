#include "tad.h"

void Inicializar(Pilha* pilha) {
    pilha->topo = NULL;
}

int PilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void Empilhar(Pilha* pilha, float num) {
    No* novo = (No*)malloc(sizeof(No));
    novo->num = num;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

float Maior(Pilha *pilha){
    No *aux = pilha->topo;
    float maior = pilha->topo->num;

    while(aux != NULL){
        if(aux->num > maior){
            maior = aux->num;
        }
        aux = aux->proximo;
    }

    return maior;
}
float Menor(Pilha *pilha){
    No *aux = pilha->topo;
    float menor = pilha->topo->num;

    while(aux != NULL){
        if(aux->num < menor){
            menor = aux->num;
        }
        aux = aux->proximo;
    }

    return menor;
}

float Media(Pilha *pilha){
    No *aux = pilha->topo;
    float media = 0, n = 0;

    while(aux != NULL){
        media += aux->num;
        n++;
        aux = aux->proximo;
    }

    return media/n;
}