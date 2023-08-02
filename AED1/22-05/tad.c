#include "tad.h"

void criar_pilha(Pilha *pilha){
    pilha->topo = NULL;
}

int isEmpty(Pilha *pilha){
    if(pilha->topo == NULL){
        return 1;
    } else{
        return 0;
    }
}

void empilha(Pilha *pilha, Produto p){
    if(isEmpty(pilha)){
        No *novo = (No*)malloc(sizeof(No));
        novo->produto.codigo = p.codigo;
        strcpy(novo->produto.nome, p.nome);
        novo->produto.quantidade = p.quantidade;

        novo->proximo = NULL;
        pilha->topo = novo;
    } else{
        No *novo = (No*)malloc(sizeof(No));
        novo->produto.codigo = p.codigo;
        strcpy(novo->produto.nome, p.nome);
        novo->produto.quantidade = p.quantidade;

        novo->proximo = pilha->topo;
    	pilha->topo = novo;
    }
}

struct Produto desempilha(Pilha *pilha){
     if (isEmpty(pilha)) {
        printf("A pilha está vazia.\n");
        return;
    } else {
        No *removido = pilha->topo;
        struct Produto x = removido->produto;
        pilha->topo = pilha->topo->proximo;
        free(removido);
        
        return x;
    } 
}

void imprime_topo(Pilha *pilha){
    if (isEmpty(pilha)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Código: %d\n", pilha->topo->produto.codigo);
        printf("Produto: %s\n", pilha->topo->produto.nome);
        printf("Quantidade no estoque: %d\n", pilha->topo->produto.quantidade);
    }    
}

int qtd_estoque(Pilha *pilha){
    int i = 0;
    No *atual = pilha->topo;
    while (atual != NULL)
    {
        i += atual->produto.quantidade;
        atual = atual->proximo;
    }
    
    return i;
}
