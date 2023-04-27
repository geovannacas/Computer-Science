#include <stdio.h>

int somadobro(int *a, int *b){
    *a *= 2;
    *b *=2;

    return *a + *b;
}

int main(){
    int x, y;

    printf("Digite o primeiro número: ");
    scanf("%d", &x);
    printf("Digite o segundo número: ");
    scanf("%d", &y);

    printf("O resultado é: %d\n", somadobro(&x, &y));
    printf("O novo valor de a é: %d\n", x);
    printf("O novo valor de b é: %d\n", y);

    return 0;
}