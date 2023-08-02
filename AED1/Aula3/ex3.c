#include <stdio.h>

int parimpar(int n){
    if(n % 2 == 0){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    int n;

    printf("Digite o número desejado:\n");
    scanf("%d", &n);

    if(parimpar(n) == 0){
        printf("Esse número é ímpar.\n");
    } else{
        printf("Esse número é par.\n");
    }

    return 0;
}