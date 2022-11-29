#include <stdio.h>

int main(){
    int i = 0, num, n, num2, x, y, cont, total, j;
    scanf("%d", &cont);
    scanf("%d", &x);
    scanf("%d", &y);

    scanf("%d", &num);
    scanf("%d", &num2);

    if(cont == 1){
        printf("%d", num);
        cont--;
    }

    if(cont != 0){
        printf("%d,%d", num, num2);

        cont = cont-2;
    }

    if(cont != 0){
        total =  num*y + num2*x;
        n = total;
        cont--;
        printf(",%d", total);
    }

    if(cont != 0){
        total =  num2*y + n*x;
        j = total;
        cont--;
        printf(",%d", total);
    }

    i = cont;

    while(i > 0){
        total =  n*y + j*x;
        n = j;
        j = total;

        printf(",%d", total);
        i--;
    }

    printf("\n");


    return 0;
}