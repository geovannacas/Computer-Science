#include <stdio.h>

int main(){
    int n1, *num1;
    double n2, *num2;

    num1 = &n1;
    num2 = &n2;
    
    printf("Digite o valor de n1: ");
    scanf("%d", &n1);
    printf("Digite o valor de n2: ");
    scanf("%lf", &n2);

    printf("Valor de n1 antes da modificação: %d\n", n1);
    printf("Valor de n2 antes da modificação: %.1lf\n", n2);

    *num1 += 10;
    *num2 *= 10;

    printf("Valor de n1 depois da modificação: %d\n", n1);
    printf("Valor de n2 depois da modificação: %.1lf\n", n2);

    return 0;
}