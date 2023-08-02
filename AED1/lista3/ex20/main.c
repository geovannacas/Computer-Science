#include "tad.h"

int main(){
    Pilha pilha;
    Inicializar(&pilha);
    
    int num;

    printf("Digite um número (0 para sair): ");
    scanf("%d", &num);

    while(num != 0){
        Empilhar(&pilha, num);
        printf("Digite um número (0 para sair): ");
        scanf("%d", &num);
    }

    Pilha pilha2;
    Inicializar(&pilha2);

    Imprime(&pilha);

    pilha2 = Copiar(&pilha);
    printf("Cópia - ");

    Imprime(&pilha2);

    return 0;
}