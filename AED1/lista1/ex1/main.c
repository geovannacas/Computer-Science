#include "tad.h"

int main(){
    TipoLista lista1, lista2, listaconcatenada;
    int i, valor;

    Inicializar(&lista1);
    Inicializar(&lista2);

    for(i = 0; i < 5; i++){
        printf("Digite o %d valor para a lista 1: ", i+1);
        scanf("%d", &valor);
        Insere(valor, &lista1);
    }

    printf("\n");

    for(i = 0; i < 5; i++){
        printf("Digite o %d valor para a lista 2: ", i+1);
        scanf("%d", &valor);
        Insere(valor, &lista2);
    }

    printf("\n");

    listaconcatenada = Concatenar(lista1, lista2);

    printf("A Lista 1 e 2 concatenada é:\n");    
    Imprime(listaconcatenada);

    return 0;
}