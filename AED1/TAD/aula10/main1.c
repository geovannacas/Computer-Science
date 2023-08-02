#include <stdio.h>
#include "tad1.h"

int main(){

    TipoLista lista;
    int item, menor, impares;
    int *valor;
    TipoApontador p;
    int i;
    int max = 5;

    Inicializar(&lista);

    for (i = 0; i < max; i++) {
        printf("Digite um valor: ");
        scanf("%d", &item);
        Insere(item, &lista);
    }

    Imprime(lista);
    printf("\n");

    p = lista.Primeiro->Prox;

    Retira(p, &lista);
    
    Imprime(lista);
    impares = Conta_Impares(lista);
    menor = Menor_Valor(lista);
    printf("O menor valor da lista é: %d\nA quantidade de valores ímpares na lista é: %d\n", menor, impares);

    return 0;
}