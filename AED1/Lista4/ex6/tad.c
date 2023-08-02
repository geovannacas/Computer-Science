#include "tad.h"

void Inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->final = NULL;
}

int FilaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void Inserir(Fila *fila, char nome[50]){
    No *aux = (No*)malloc(sizeof(No));
    strcpy(aux->nome, nome);
    aux->proximo = NULL;

    if(FilaVazia(fila)){
        fila->inicio = aux;
        fila->final = aux;
    } else{
        fila->final->proximo = aux;
        fila->final = aux;
    }
}

void OrdenarPorSelecao(Fila* fila) {
    if (FilaVazia(fila) || fila->inicio == fila->final) {
        return; // Nada para ordenar ou apenas um elemento na fila.
    }

    No* i = fila->inicio;
    while (i->proximo != NULL) {
        No* minimo = i;
        No* j = i->proximo;

        while (j != NULL) {
            if (strcmp(j->nome, minimo->nome) < 0) {
                minimo = j;
            }
            j = j->proximo;
        }

        if (minimo != i) {
            char temp[50];
            strcpy(temp, i->nome);
            strcpy(i->nome, minimo->nome);
            strcpy(minimo->nome, temp);
        }

        i = i->proximo;
    }
}

void OrdenarPorInsercao(Fila* fila) {
    if (FilaVazia(fila) || fila->inicio == fila->final) {
        return; // Nada para ordenar ou apenas um elemento na fila.
    }

    No* i = fila->inicio->proximo;
    while (i != NULL) {
        char chave[50];
        strcpy(chave, i->nome);

        No* j = i->proximo;
        No* prev = i;

        while (j != NULL && strcmp(j->nome, chave) < 0) {
            strcpy(prev->nome, j->nome);
            prev = j;
            j = j->proximo;
        }

        strcpy(prev->nome, chave);

        i = i->proximo;
    }
}

void ImprimirFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        printf("%s ", atual->nome);
        atual = atual->proximo;
    }
    printf("\n");
}

void LiberarFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    fila->inicio = NULL;
    fila->final = NULL;
}
