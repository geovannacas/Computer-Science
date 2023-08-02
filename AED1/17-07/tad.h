#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Info{
    int ID;
} Info;

typedef struct Vetor{
    Info elementos[MAX];
    int n;
} Vetor;

void Inicializar(Vetor *vetor);

void Insere(Vetor *vetor, Info num);

int Pesquisa(Vetor *vetor, int x);