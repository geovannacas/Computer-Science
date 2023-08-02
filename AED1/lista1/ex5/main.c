#include "tad.h"

int main(){
    TipoLista lista;
    int i, valor, media;

    Inicializar(&lista);

    for(i = 0; i < MAXTAM; i++){
        printf("Digite o %d valor para a lista: ", i+1);
        scanf("%d", &valor);
        Insere(valor, &lista);
    }

    printf("\n");

    media = Media(lista);

    printf("A média dos valores da lista é: %d\n", media);

    return 0;
}