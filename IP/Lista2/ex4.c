#include <stdio.h>

int somaDivisores(int n){
    int i, soma = 0;

    for(i = 1; i <= n; i++){
        if(n % i == 0){
            if(i == 1){
                printf("%d = %d", n, i);
            } else if(i == n){
                if(soma == n){
                    printf(" = %d (NUMERO PERFEITO)\n", soma);
                } else{
                    printf(" = %d (NUMERO NAO E PERFEITO)\n", soma);
                }
            } else{
                printf(" + %d", i);
            }
            soma += i;
        }
    }

    return(soma);
}

int main(){
    int n;

    scanf("%d", &n);
    somaDivisores(n);

    return 0;
}