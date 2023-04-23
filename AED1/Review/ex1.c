#include <stdio.h>

int main(){
    double salario, salariomin;

    printf("Qual o salário?\n");
    scanf("%lf", &salario);
    printf("Qual o salário mínimo?\n");
    scanf("%lf", &salariomin);

    printf("Total: %.1lf salários mínimos.\n", salario/salariomin);

    return 0;
}
