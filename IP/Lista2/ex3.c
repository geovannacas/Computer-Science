#include <stdio.h>

int separaDigitos(int num){
    int first, second, third;

    first = (num/100);
    num = num - (first*100);
    second = (num/10);
    num = num - (second*10);
    third = num;

    num = first+(second*10)+(third*100);
    
    return(num);
}

int main(){
    int num, first, second, third;
    scanf("%d", &num);

    printf("%d\n", separaDigitos(num));

    return 0;
}