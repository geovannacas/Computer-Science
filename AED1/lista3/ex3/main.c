#include "tad.h"

int main(){
    Fila fila;
    Inicializar(&fila);

    int prioridade, max, p;
    float valor;

    printf("Quantos elementos deseja inserir?\n");
    scanf("%d", &max);

    for(int i = 0; i < max; i++){
        printf("Digite o valor: ");
        scanf("%f", &valor);
        printf("Digite a prioridade: ");
        scanf("%d", &prioridade);

        Enfileirar(&fila, valor, prioridade);
    }

    Fila filad1;
    Inicializar(&filad1);

    Fila filad2;
    Inicializar(&filad2);

    printf("Digite o valor de prioridade a ser analisado: ");
    scanf("%d", &p);

    filad1 = divPrioridade(&fila, p);
    filad2 = divPrioridadeResto(&fila, p);

    printf("Prioridades menores ou iguais a %d:\n", p);
    Imprime(&filad1);
    printf("Prioridades maiores que %d:\n", p);
    Imprime(&filad2);

    return 0;
}