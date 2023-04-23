#include <stdio.h>

unsigned long int fat(unsigned int n){
    int f = 1, i;
    for(i = 1; i <= n; i++){
        f *= i;
    }
    return(f);
}

int main(){
    int n, result;
    scanf("%d", &n);

    result = fat(n);

    printf("%d! = %d\n", n, result);

    return 0;
}