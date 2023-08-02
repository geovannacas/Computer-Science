#include "tad.h"

int main() {
    Pilha pilha;
    Inicializar(&pilha);

    int n;
    char caractere;
    printf("Digite a quantidade de caracteres: ");
    scanf("%d", &n);
    
    getchar();

    printf("Insira os caracteres: ");
    for(int i = 0; i < n; i++){
        scanf("%c", &caractere);
        Empilhar(&pilha, caractere);
    }
    VerificarPalindromo(&pilha); 

    return 0;
}