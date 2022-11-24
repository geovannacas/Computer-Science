#include <stdio.h>

int main() {
    float F, P, C, MM;
    scanf("%f", &F);
    scanf("%f", &P);

    C = 5*(F-32)/9;
    MM = 25.4*P;

    printf("O VALOR EM CELSIUS = %.2f\n", C);
    printf("A QUANTIDADE DE CHUVA E = %.2f\n", MM);  

    return 0;
}