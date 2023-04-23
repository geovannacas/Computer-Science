#include <stdio.h>

int main(){
    int n, x1, x2, x3, a;

    scanf("%d", &n);

    x1 = n%1000/100;
    x2 = n%100/10;
    x3 = n%10;

    printf("%d%d%d\n", x3, x2, x1);

    return 0;
}