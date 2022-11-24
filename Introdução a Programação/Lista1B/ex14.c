#include <stdio.h>

int main(){
    int n, i, x=0;

    scanf("%d", &n);

    printf("%d = ", n);

    for(i = 1; i <= n; i++){
        if(n % i == 0){
            x += i;

            if(i != 1 && i != n){
                printf(" + ");
            }

            if(i != n){
                printf("%d", i);
            }

            if(i == n){
                x -= i;
                if(x == n){
                    printf(" = %d (NUMERO PERFEITO)\n", x);
                } else {
                    printf(" = %d (NUMERO NAO E PERFEITO)\n", x);
                }
                break;
            }
        }

    }

    return 0;
}