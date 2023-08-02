#include "tad1.h"

void criar_pilha(Pilha *pilha){
    pilha->topo = -1;
}

bool esta_vazia(Pilha *pilha){
    return pilha->topo == -1;
}

void empilhar(Pilha *pilha, int x){
    if(pilha->topo < MAX - 1){
        pilha->topo++;
        pilha->pilha[pilha->topo] = x;
    } else{
        printf("Pilha está cheia\n");
    }
}

int desempilhar(Pilha *pilha){
    if(!esta_vazia(pilha)){
        int x = pilha->pilha[pilha->topo];
        pilha->topo--;
        return x;
    } else{
        printf("Pilha está vazia\n");
        return -1;
    }
}

int tamanho(Pilha *pilha){
    return pilha->topo +1;
}

void imprime(Pilha *pilha){
    printf("Elementos da pilha\n");
    for(int i = pilha->topo; i >= 0; i--){
        printf("%d\n", pilha->pilha[i]);
    }
}
