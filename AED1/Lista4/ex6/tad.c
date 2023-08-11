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

void OrdenarPorSelecao(Lista *lista) {
    for (int i = 0; i < lista->indice - 1; i++) {
        int min = i;

        for (int j = i + 1; j < lista->indice; j++) {
            if (strcmp(lista->elementos[j].nome, lista->elementos[min].nome) < 0) {
                min = j;
            }
        }

        if (min != i) {
            Item temp = lista->elementos[i];
            lista->elementos[i] = lista->elementos[min];
            lista->elementos[min] = temp;
        }
    }
}

void OrdenarPorInsercao(Lista *lista) {
    for (int i = 1; i < lista->indice; i++) {
        Item chave = lista->elementos[i];
        int j = i - 1;

        while (j >= 0 && strcmp(lista->elementos[j].nome, chave.nome) > 0) {
            lista->elementos[j + 1] = lista->elementos[j];
            j--;
        }

        lista->elementos[j + 1] = chave;
    }
}


void ImprimirLista(Lista *lista) {
    for (int i = 0; i < lista->indice; i++) {
        printf("%s ", lista->elementos[i].nome);
    }
    printf("\n");
}