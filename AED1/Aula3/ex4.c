#include <stdio.h>
#include <math.h>

int recursao(int x, int n){
    if(n == 0){
        return 1;
    } else{
        return x * recursao(x, n-1);
    }
}


int main(){
    int x, n;

    printf("Digite o número x e n:\n");
    scanf("%d %d", &x, &n);

    printf("O resultado é: %d\n", recursao(x,n));

    return 0;
}