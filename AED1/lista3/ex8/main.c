#include "tad.h"

int main(){
    Pilha pilha;
    Inicializar(&pilha);

    int max;
    float num;

    printf("Escolha a quantidade de elementos inseridos: ");
    scanf("%d", &max);

    for(int i = 0; i < max; i++){
        printf("Digite um valor: ");
        scanf("%f", &num);
        Empilhar(&pilha, num);
    }

    printf("O maior número é: %.1f\n", Maior(&pilha));
    printf("O menor número é: %.1f\n", Menor(&pilha));
    printf("A média aritmética é: %.2f\n", Media(&pilha));

    return 0;
}