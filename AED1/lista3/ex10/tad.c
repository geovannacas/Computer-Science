#include "tad.h"

void Inicializar(Pilha* pilha) {
    pilha->topo = NULL;
}

int PilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void Empilhar(Pilha* pilha, char caractere) {
    No* novo = (No*)malloc(sizeof(No));
    novo->caractere = tolower(caractere);
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void VerificarPalindromo(Pilha *pilha){
    int x = 0, tamanho= 0;
    Pilha pilhac;
    Inicializar(&pilhac);
    No *aux = pilha->topo;

    while(aux != NULL){
        Empilhar(&pilhac, aux->caractere);
        tamanho++;
        aux = aux->proximo;
    }

    No *aux2 = pilhac.topo;
    aux = pilha->topo;


    while(aux != NULL){
        if(aux2->caractere == aux->caractere){
            x++;
        }
        aux2 = aux2->proximo;
        aux = aux->proximo;
    }

    if(x == tamanho){
        printf("É um palindromo.\n");
    } else{
        printf("Não é um palindromo.\n");
    }

}