#include "tad.h"

int main(){
    Fila fila;
    Inicializar(&fila);
    Fila fila2;
    Inicializar(&fila2);

    int max, num;
    printf("Quantos elementos deseja inserir na fila 1?\n");
    scanf("%d", &max);

    for(int i = 0; i < max; i++){
        printf("Digite o valor: ");
        scanf("%d", &num);

        Enfileirar(&fila, num);
    }

    printf("Quantos elementos deseja inserir na fila 2?\n");
    scanf("%d", &max);

    for(int i = 0; i < max; i++){
        printf("Digite o valor: ");
        scanf("%d", &num);

        Enfileirar(&fila2, num);
    }
    
    Fila fila3;
    Inicializar(&fila3);

    SomaFilas(&fila, &fila2, &fila3);

    printf("--Lista final--\n");
    Imprime(&fila3);

    return 0;
}