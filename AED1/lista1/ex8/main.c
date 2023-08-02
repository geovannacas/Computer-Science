#include "tad.h"

int main(){
    int n;
    printf("Quantos elementos terá no vetor 1?\n");
    scanf("%d", &n);

    int vetor[n];

    printf("Insira os elementos do vetor 1:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    Lista *lista;

    lista = Vetor(vetor, n);
    Imprime(lista);

    RemoverRepetidos(lista);
    Imprime(lista);

    free(lista);
    
    return 0;
}