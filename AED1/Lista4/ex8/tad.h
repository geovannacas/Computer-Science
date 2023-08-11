#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int vetor[MAX_SIZE];
    int indice; 
} Vetor;

void Inicializar(Vetor *vetor);
void Inserir(Vetor *vetor, int n);
void MergeSort(Vetor *resultado, Vetor *vetor1, Vetor *vetor2, Vetor *vetpr3);
void Imprime(Vetor vetor);
