#include "tad.h"

void Inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void AdicionarAviao(Fila *fila, int id, char nome[50], int capacidade, char tipo[50]){
    No *novo = (No*)malloc(sizeof(No));

    novo->aviao.id = id;
    strcpy(novo->aviao.nome, nome);
    strcpy(novo->aviao.tipo, tipo);
    novo->aviao.capacidade = capacidade;
    novo->proximo = NULL;

    if(FilaVazia(fila)){
        fila->inicio = novo;
        fila->fim = novo;
    } else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

No *AutorizarDecolagem(Fila *fila){
    if(FilaVazia(fila)){
        printf("Erro: fila está vazia\n");
        return NULL;
    }

    No* primeiro = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return primeiro;
}

int NumeroAviao(Fila *fila){
    No *aux = fila->inicio;
    int num = 0;

    while (aux != NULL)
    {
        num++;
        aux = aux->proximo;
    }
    
    return num;
}

void ListarFila(Fila *fila){
    No *aux = fila->inicio;

    while(aux != NULL){

        printf("ID: %d - Nome: %s\n", aux->aviao.id, aux->aviao.nome);

        aux = aux->proximo;
    }
}

void ImprimePrimeiro(Fila *fila){
    printf("ID: %d - Nome: %s - Tipo: %s - Capacidade: %d\n", fila->inicio->aviao.id, fila->inicio->aviao.nome, fila->inicio->aviao.tipo, fila->inicio->aviao.capacidade);
}