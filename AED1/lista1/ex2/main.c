#include "tad.h"

int main(){
    TipoLista lista;
    int i, valor, n;

    Inicializar(&lista);

    for(i = 0; i < MAXTAM; i++){
        printf("Digite o %d valor para a lista: ", i+1);
        scanf("%d", &valor);
        Insere(valor, &lista);
    }

    printf("\n");

    printf("Insira o valor dos N primeiros elementos a serem removidos da lista: ");
    scanf("%d", &n);
    Remover(n, &lista);

    return 0;
}