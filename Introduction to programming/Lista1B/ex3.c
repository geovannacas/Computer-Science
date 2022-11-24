#include <stdio.h>

int main(){
    int x, y, n, total;
    scanf("%d %d", &x, &y);

    if(x % 2 == 0){
        printf("%d ", x);
        while(y > 1){
            x += 2;
            printf("%d ", x);
            y--;
        }
        printf("\n");
    } else{
        printf("O PRIMEIRO NUMERO NAO E PAR\n");
    }

    return 0;
}