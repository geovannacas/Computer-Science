#include <stdio.h>
#include <math.h>

double raizesEq2Grau(double a, double b, double c){

    double delta, x1, x2;

    delta = b*b-4*a*c;

    if(delta > 0){
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        if(x1 < x2){
            printf("RAIZES DISTINTAS\n");
            printf("X1 = %.2lf\n", x1);
            printf("X2 = %.2lf\n", x2);
        } else if(x2 < x1){
            printf("RAIZES DISTINTAS\n");
            printf("X1 = %.2lf\n", x2);
            printf("X2 = %.2lf\n", x1);
        }
    } else if(delta == 0){
        x1 = -b/(2*a);
        printf("RAIZ UNICA\n");
        printf("X1 = %.2lf\n", x1);
    } else if(delta < 0){
        printf("RAIZES IMAGINARIAS\n");
    }

    return(delta);
}


int main(){
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    raizesEq2Grau(a, b, c);

    return 0;
}