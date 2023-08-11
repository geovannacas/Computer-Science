#include "tad.h"

void Inicializar(Lista *lista) {
    lista->indice = 0;
}

int ListaVazia(Lista *lista) {
    return lista->indice == 0;
}

int ListaCheia(Lista *lista) {
    return lista->indice == MAX_SIZE;
}

void Inserir(Lista *lista, char nome[50]) {
    if (!ListaCheia(lista)) {
        strcpy(lista->elementos[lista->indice].nome, nome);
        lista->indice++;
    }
}

int Particionar(Lista *lista, int inicio, int fim) {
    Item pivo = lista->elementos[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (strcmp(lista->elementos[j].nome, pivo.nome) <= 0) {
            i++;
            Item temp = lista->elementos[i];
            lista->elementos[i] = lista->elementos[j];
            lista->elementos[j] = temp;
        }
    }

    Item temp = lista->elementos[i + 1];
    lista->elementos[i + 1] = lista->elementos[fim];
    lista->elementos[fim] = temp;

    return i + 1;
}

void Quicksort(Lista *lista, int inicio, int fim){
    if (inicio < fim) {
        int indiceParticao = Particionar(lista, inicio, fim);
        Quicksort(lista, inicio, indiceParticao - 1);
        Quicksort(lista, indiceParticao + 1, fim);
    }
}


void ImprimirLista(Lista *lista) {
    for (int i = 0; i < lista->indice; i++) {
        printf("%s ", lista->elementos[i].nome);
    }
    printf("\n");
}