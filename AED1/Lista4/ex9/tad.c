#include "tad.h"

void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(Aluno vetor[], int inicio, int fim) {
    Aluno pivo = vetor[fim];
    int indicePivo = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j].Nota >= pivo.Nota) {
            indicePivo++;
            trocar(&vetor[indicePivo], &vetor[j]);
        }
    }

    trocar(&vetor[indicePivo + 1], &vetor[fim]);
    return indicePivo + 1;
}

void quickSort(Aluno vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, fim);
    }
}

void merge(Aluno vetor[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Aluno L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vetor[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (L[i].Matricula <= R[j].Matricula) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Aluno vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
