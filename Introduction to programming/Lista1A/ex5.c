#include <stdio.h>

int main() {

    double a, b, c, x;

    scanf("%lf", &x);

    a = x;

    scanf("%lf", &x);

    if(x <= a){
        b = a;
        a = x;
    } else{
        b = x;
    }

    scanf("%lf", &x);

    if(x >= b){
        c = x;
    } else if(x >= a){
        c = b;
        b = x;
    } else {
        c = b;
        b = a;
        a = x;
    }

    printf("%.2lf, %.2lf, %.2lf\n", a, b, c);

    return 0;
}