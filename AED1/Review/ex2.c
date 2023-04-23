#include <stdio.h>

int main(){
    int num1, num2;

    printf("Insira um número:\n");
    scanf("%d", &num1);
    printf("Insira outro número:\n");
    scanf("%d", &num2);

    printf("A soma é: %d\n", num1+num2);
    if(num1 > num2){
        printf("Maior número: %d\nMenor número: %d\n", num1, num2);
    } else if(num2 > num1){
        printf("Maior número: %d\nMenor número: %d\n", num2, num1);
    } else{
        printf("Os números %d e %d são iguais\n", num1, num2);
    }

    return 0;
}