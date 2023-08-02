#include "tad.h"

int main(){
    Pilha pilha;
    int x;
    criar_pilha(&pilha);


    if(esta_vazia(&pilha) == 1){
        printf("Está vazia\n");
    } else{
        printf("Não está vazia\n");
    }

    printf("Digite 10 números para a empilhar:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &x);
        empilhar(&pilha, x);
    }

    imprime(&pilha);

    printf("Tamanho da pilha: %d\n", tamanho(&pilha));

    int desemp = desempilhar(&pilha);

    printf("Item desempilhado: %d\n", desemp); 

    imprime(&pilha);

    return 0;
}