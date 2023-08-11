#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct _pessoa_ {
    unsigned int Matricula;
    float Nota;
} Aluno;

typedef struct {
    Aluno elementos[MAX_SIZE];
    int indice;
} Lista;

void trocar(Aluno *a, Aluno *b);
int particionar(Aluno vetor[], int inicio, int fim);
void quickSort(Aluno vetor[], int inicio, int fim);
void merge(Aluno vetor[], int inicio, int meio, int fim);
void mergeSort(Aluno vetor[], int inicio, int fim);