#include "tad.h"

int main(){
    Fila fila;
    Inicializar(&fila);
    int num;

    printf("Digite um número (0 para sair): ");
    scanf("%d", &num);

    while(num != 0){
        Enfilerar(&fila, num);
        printf("Digite um número (0 para sair): ");
        scanf("%d", &num);
    }

    Imprime(&fila);

    printf("Retirado Negativos - ");

    RemoverNeg(&fila);

    Imprime(&fila);

    return 0;
}