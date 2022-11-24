#include <stdio.h>
 
int main(){
    float a, b, c, d, n;
    n = 0;
 
    scanf("%f %f %f %f", &a, &b, &c, &d);
 
    if(a > b){
        n = b;
        b = a;
        a = n;
    }
    if(a > c){
        n = c;
        c = a;
        a = n;
    }
    if(b > c){
        n = c;
        c = b;
        b = n;
    }
    if(c > d){
        n = d;
        d = c;
        c = n;
    }

    printf("%.2f, %.2f, %.2f, %.2f\n", a, b, c, d);

    return 0;
}