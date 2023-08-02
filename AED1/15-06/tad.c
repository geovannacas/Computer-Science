#include "tad.h"

void inicializar(FilaFuncionario *fila){
    fila->inicio = 0;
    fila->fim = fila->inicio;
}

int vazia(FilaFuncionario *fila){
    return fila->inicio == fila->fim;
}

void enfileirar(FilaFuncionario *fila, int codigo, float salario){
    fila->fila[fila->fim].codigo = codigo;
    fila->fila[fila->fim].salario = salario;
    fila->fim++;
}

void desenfileirar(FilaFuncionario *fila){
    
}

