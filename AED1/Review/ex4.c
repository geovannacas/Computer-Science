#include <stdio.h>

int main(){
    int n, maior;

    printf("Digite a quantidade de números:\n");
    scanf("%d", &n);

    int num[n];

    printf("Digite a sequência:\n");
    for(int j = 0;j < n; j++){
        scanf("%d", &num[j]);
    }

    for(int i = 1; i < n; i++){
        if(num[i] > num[i-1]){
            maior = num[i];
        }
    }

    printf("O maior número da sequência é: %d\n", maior);

    return 0;
}