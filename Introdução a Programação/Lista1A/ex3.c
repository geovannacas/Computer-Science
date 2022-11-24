#include <stdio.h>

int main(){
    float A, B, C, DELTA;

    scanf("%f", &A);
    scanf("%f", &B);
    scanf("%f", &C);

    DELTA = B*B - 4*A*C;

    printf("O VALOR DE DELTA E = %.2f\n", DELTA);

    return 0;
}