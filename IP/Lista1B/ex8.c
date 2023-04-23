#include <stdio.h>

int main(){
    int N, i, j, x=1;

    scanf("%d", &N);

    if(N <= 1){
        printf("Campeonato invalido!\n");
    } else{
        for(i = 1; i <= N; i++){
        for(j = i + 1; j <= N; j++){
            printf("Final %d: Time%d X Time%d\n", x, i, j);
            x++;
        }
    }
    }

    return 0;
}