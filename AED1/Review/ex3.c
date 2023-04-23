#include <stdio.h>

int adicao(double x, double y){
    return x+y;
}
int subtracao(double x, double y){
    return x-y;
}
int multiplicacao(double x, double y){
    return x*y;
}
int divisao(double x, double y){
    return x/y;
}

int main(){
    int total = 0, escolha;
    double num1, num2;

    printf("Digite dois números:\n");
    scanf("%lf %lf", &num1, &num2);
    printf("Digite a operação desejada:\n1 - Adição\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        total = adicao(num1, num2);
        printf("O resultado é: %d\n", total);
        break;
    case 2:
        total = subtracao(num1, num2);
        printf("O resultado é: %d\n", total);
        break;
    case 3:
        total = multiplicacao(num1, num2);
        printf("O resultado é: %d\n", total);
        break;
    case 4:
        total = divisao(num1, num2);
        printf("O resultado é: %d\n", total);
        break;
    default:
        break;
    }


    return 0;
}