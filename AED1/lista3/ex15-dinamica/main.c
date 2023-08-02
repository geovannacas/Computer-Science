#include "tad.h"

int main(){
    Fila fila;
    Fila filaInvertida;
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

    filaInvertida = Inverter(&fila);

    printf("Invertida - ");

    Imprime(&filaInvertida);

    return 0;
}