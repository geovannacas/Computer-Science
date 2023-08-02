#include <stdio.h>

// Fatorial recursivo
unsigned long int fatorial(unsigned long int n) {
    if (n == 0) {
        return (1);
    } else {
        return (n * fatorial(n-1));
    }
}

int main(){
    int x;

    printf("Digite um número: ");
    scanf("%d", &x);

    printf("Fatorial de %d é: %ld\n", x, fatorial(x));
}