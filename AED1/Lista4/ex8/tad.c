#include "tad.h"

void Inicializar(Vetor *vetor) {
    vetor->indice = 0;
}

void Inserir(Vetor *vetor, int n) {
    if (vetor->indice < MAX_SIZE) {
        vetor->vetor[vetor->indice++] = n;
    }
}

void MergeSort(Vetor *resultado, Vetor *vetor1, Vetor *vetor2, Vetor *vetor3) {
    int i = 0, j = 0, k = 0;
    
    while (i < vetor1->indice && j < vetor2->indice && k < vetor3->indice) {
        if (vetor1->vetor[i] <= vetor2->vetor[j] && vetor1->vetor[i] <= vetor3->vetor[k]) {
            resultado->vetor[resultado->indice++] = vetor1->vetor[i++];
        } else if (vetor2->vetor[j] <= vetor1->vetor[i] && vetor2->vetor[j] <= vetor3->vetor[k]) {
            resultado->vetor[resultado->indice++] = vetor2->vetor[j++];
        } else {
            resultado->vetor[resultado->indice++] = vetor3->vetor[k++];
        }
    }

    while (i < vetor1->indice) {
        resultado->vetor[resultado->indice++] = vetor1->vetor[i++];
    }

    while (j < vetor2->indice) {
        resultado->vetor[resultado->indice++] = vetor2->vetor[j++];
    }

    while (k < vetor3->indice) {
        resultado->vetor[resultado->indice++] = vetor3->vetor[k++];
    }
}

void Imprime(Vetor vetor) {
    for (int i = 0; i < vetor.indice; i++) {
        printf("%d ", vetor.vetor[i]);
    }
    printf("\n");
}
