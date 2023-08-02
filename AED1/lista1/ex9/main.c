#include "tad.h"

int main(){
    int n1, n2;
    printf("Quantos elementos terá no vetor 1?\n");
    scanf("%d", &n1);
    printf("Quantos elementos terá no vetor 2?\n");
    scanf("%d", &n2);

    int vetor1[n1], vetor2[n2];

    printf("Insira os elementos do vetor 1:\n");
    for(int i = 0; i < n1; i++){
        scanf("%d", &vetor1[i]);
    }

    printf("Insira os elementos do vetor 2:\n");
    for(int i = 0; i < n2; i++){
        scanf("%d", &vetor2[i]);
    }

    Lista *lista1;
    Lista *lista2;
    Lista *listaintercalada;

    lista1 = Vetor(vetor1, n1);
    Imprime(lista1);


    lista2 = Vetor(vetor2, n2);
    Imprime(lista2);

    listaintercalada = IntercalarListas(lista1, lista2);
    Imprime(listaintercalada);

    free(lista1);
    free(lista2);
    free(listaintercalada);

    return 0;
}