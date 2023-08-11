#include "tad.h"

int main() {
    int vetor[] = {2, 4, 7, 4, 8, 4, 6, 9, 4, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int chave = 4;
    
    int ocorrencias_sequencial[MAX];
    int quant_sequencial = buscaSequencial(vetor, tamanho, chave, ocorrencias_sequencial);

    int ocorrencias_binaria[MAX];
    int quant_binaria = buscaBinaria(vetor, tamanho, chave, ocorrencias_binaria);

    printf("Busca Sequencial:\n");
    for (int i = 0; i < quant_sequencial; i++) {
        printf("Chave %d encontrada na posicao %d\n", chave, ocorrencias_sequencial[i]);
    }
    printf("Total de ocorrencias: %d\n", quant_sequencial);

    printf("\nBusca Binaria:\n");
    for (int i = 0; i < quant_binaria; i++) {
        printf("Chave %d encontrada na posicao %d\n", chave, ocorrencias_binaria[i]);
    }
    printf("Total de ocorrencias: %d\n", quant_binaria);

    return 0;
}
