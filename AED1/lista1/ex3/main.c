#include "tad.h"

int main(){
    TipoLista lista;
    int i, posicao, valor;

    Inicializar(&lista);

    for(i = 0; i < MAXTAM; i++){
        printf("Digite o %d valor para a lista: ", i+1);
        scanf("%d", &valor);
        Insere(valor, &lista);
    }

    printf("\n");

    MaiorElemento(lista, &posicao, &valor);

    return 0;
}