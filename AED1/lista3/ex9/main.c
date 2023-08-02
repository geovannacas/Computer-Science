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

    Pilha pilha2;
    Inicializar(&pilha2);

    Imprime(&pilha);

    pilha2 = Inverter(&pilha);
    printf("Pilha Invertida.\n");

    Imprime(&pilha2);

    return 0;
}