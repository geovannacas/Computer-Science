#include "tad.h"

void Inicializar(Pilha* pilha) {
    pilha->topo = -1;
}

int PilhaVazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

int PilhaCheia(Pilha* pilha) {
    return (pilha->topo == MAX_SIZE - 1);
}

void Empilhar(Pilha* pilha, int num) {
    if (PilhaCheia(pilha)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    
    pilha->topo++;
    pilha->pilha[pilha->topo] = num;
}

Pilha Inverter(Pilha *pilha){
    Pilha pilhainvertida;
    Inicializar(&pilhainvertida);

    for (int i = pilha->topo; i >= 0; i--) {
        Empilhar(&pilhainvertida, pilha->pilha[i]);
    }
    
    return pilhainvertida;
}

void Imprime(Pilha* pilha) {
    printf("Elementos da pilha:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d\n", pilha->pilha[i]);
    }
}