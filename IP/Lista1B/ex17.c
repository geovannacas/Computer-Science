#include <stdio.h>
#include <math.h>

int main(){
    int n, i, fat = 1, j, k=1;
    double x, formula, soma;

    scanf("%lf %d", &x, &n);

    for(i = 0; i <= n; i++){
        
        for(j = 1; j <= i; j++){
            fat *= j;    
        }
        
        formula += pow(x, i)/fat;

        fat = 1;
    }

    printf("e^%.2lf = %.6lf\n", x, formula);
    
    return 0;
}