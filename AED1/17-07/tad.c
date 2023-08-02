#include "tad.h"

void Inicializar(Vetor *vetor){
    vetor->n = 0;
}

void Insere(Vetor *vetor, Info num){
    if(vetor->n == MAX){
        printf("Erro - Tabela cheia\n");
    } else{
        vetor->n++;
        vetor->elementos[vetor->n] = num;
    }
}

int Pesquisa(Vetor *vetor, int x){
    vetor->elementos[0].ID = x;
    int i = vetor->n+1;
    do{
        i--;
    } while(vetor->elementos[i].ID != x);
    return i;
}