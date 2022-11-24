#include <stdio.h>
#include <math.h>

int main(){
    double n, rk, ri = 1, x, e;

    scanf("%lf %lf", &n, &e);

    do{
        rk = (ri + (n/ri))/2;
        x = n - rk*rk;
        x = sqrt(x*x);
        ri = rk;
        printf("r: %.9lf, err: %.9lf\n", rk, x);

    } while(x > e);

    return 0;
}