#include <stdio.h>

int main(){
    int n, i=1, x=1, total;
    total = 1;

    scanf("%d", &n);

    if(n == 0){
        total = 1;
        printf("%d! = %d\n", n, total);
    } else{
        for(i; i <= n; i++){
        total *= x;
        x++;
        }

        printf("%d! = %d\n", n, total);
    }

    return 0;
}