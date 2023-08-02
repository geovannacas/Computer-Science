#include "tad.h"

int main(){
    Pilha pilha;
    Inicializar(&pilha);
    
    int max, num;

    printf("Escolha a quantidade de elementos inseridos: ");
    scanf("%d", &max);

    for(int i = 0; i < max; i++){
        printf("Digite um valor: ");
        scanf("%d", &num);
        Empilhar(&pilha, num);
    }

    int removido = Desempilhar(&pilha);

    printf("O valor armazenado no topo da pilha é %d.\n", removido);
    printf("Valor foi removido.\n");

    return 0;
}