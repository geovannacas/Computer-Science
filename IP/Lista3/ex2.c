#include <stdio.h>

int main(){
    int N, V[1001], i, x, j=0;

    scanf("%d", &N);

    while(N < 1 || N > 1000){
        scanf("%d", &N);
    }

    for(i = 0; i <  N; i++){
        scanf("%d", &V[i]);
    }

    scanf("%d", &x);

    for(i = 0; i < N; i++){
        if(x <= V[i]){
            j++;
        }
    }

    printf("%d\n", j);


    return 0;
}