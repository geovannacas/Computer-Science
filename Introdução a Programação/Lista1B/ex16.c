#include <stdio.h>
#include <math.h>

int main(){
    int n, i, fat = 1, j, k=1;
    double x, formula, soma;

    scanf("%lf %d", &x, &n);

    for(i = 0; i <= n; i++){
        
        for(j = 1; j <= i*2; j++){
            fat *= j;    
        }
        
        formula = (pow(-1, i) * pow(x, i*2))/fat;
        soma += formula;

        fat = 1;
    }

    printf("cos(%.2lf) = %.6lf\n", x, soma);
    
    return 0;
}