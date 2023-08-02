#include <stdio.h>

int menor(int a, int b){
    if(a > b){
        printf("O %d é menor.\n", b);
    } else if(b > a){
        printf("O %d é menor.\n", a);
    } else{
        printf("São iguais.\n");
    }
}

int main(){
    int x, y;

    printf("Digite um número: ");
    scanf("%d", &x);
    printf("Digite outro número: ");
    scanf("%d", &y);

    menor(x, y);

    return 0;
}