#include <stdio.h>

int main() {
    int num1, num2;

    printf("Digite o valor de a: ");
    scanf("%d", &num1);
    printf("Digite o valor de b: ");
    scanf("%d", &num2);


   if(&num1 > &num2){
        printf("O endereço de num1 (%p) é maior num2 (%p)\n", &num1, &num2);
   } else if(&num2 > &num1){
        printf("O endereço de num2 (%p) é maior num1(%p)\n", &num2, &num1);
   }
   
    return 0;
}