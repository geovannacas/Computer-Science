#include "tad.h"

int main(){
    TipoLista lista;
    int i, valor, pares;

    Inicializar(&lista);

    for(i = 0; i < MAXTAM; i++){
        printf("Digite o %d valor para a lista: ", i+1);
        scanf("%d", &valor);
        Insere(valor, &lista);
    }

    printf("\n");

    pares = NumerosPares(lista);
    printf("A lista tem %d números pares.\n", pares);

    return 0;

}