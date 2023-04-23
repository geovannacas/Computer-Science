#include <stdio.h>

int main(){
    int vetor[5000], i, x, n;

    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        vetor[n-i] = x;
    } 

    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}