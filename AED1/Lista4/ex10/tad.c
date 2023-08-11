#include "tad.h"

int buscaSequencial(int vet[], int n, int chave, int posicoes[]) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (vet[i] == chave) {
            posicoes[contador] = i;
            contador++;
        }
    }

    return contador;
}

int buscaBinaria(int vet[], int n, int chave, int posicoes[]) {
    int contador = 0;
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vet[meio] == chave) {
            posicoes[contador] = meio;
            contador++;

            int esquerda = meio - 1;
            while (esquerda >= 0 && vet[esquerda] == chave) {
                posicoes[contador] = esquerda;
                contador++;
                esquerda--;
            }

            int direita = meio + 1;
            while (direita < n && vet[direita] == chave) {
                posicoes[contador] = direita;
                contador++;
                direita++;
            }

            return contador;
        } else if (vet[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return contador;
}
