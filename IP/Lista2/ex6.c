#include <stdio.h>
#include <math.h>


double raiz(double n, double e){

    double rk, ri = 1, x;

    do{
        rk = (ri + (n/ri))/2;
        x = n - rk*rk;
        x = sqrt(x*x);
        ri = rk;
        printf("r: %.9lf, err: %.9lf\n", rk, x);

    } while(x > e);

    return(n);
}

int main(){

    double n, e;

    scanf("%lf %lf", &n, &e);

    raiz(n, e);

    return 0;
}