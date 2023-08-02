#include <stdio.h>

int T(int n){
    if(n == 1){
        return 1;
    } else{
        return 2*T(n/2) + n;
    }
}

int main(){
    int n;

    printf("Digite um número:\n");
    scanf("%d", &n);

    printf("O número é: %d\n", T(n));

    return 0;
}