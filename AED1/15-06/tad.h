#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    float salario;
} Funcionario;

typedef struct {
    Funcionario fila[100];
    int inicio;
    int fim;
} FilaFuncionario;

void inicializar(FilaFuncionario *fila);

int vazia(FilaFuncionario *fila);

void enfileirar(FilaFuncionario *fila, int codigo, float valor);

void desenfileirar(FilaFuncionario *fila);

void imprimir(FilaFuncionario *fila);