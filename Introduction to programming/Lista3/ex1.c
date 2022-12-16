#include <stdio.h>

int main(){
    int V[1000000], N;
    int n, i, j, x, m = 0;

    scanf("%d", &N);

    for(i = 0; i <  N; i++){
        scanf("%d", &V[i]);
    }

    scanf("%d", &n);

    for(j = 1; j <=  n; j++){
        scanf("%d", &x);

        for(i = 0; i <  N; i++){
            if(V[i] == x){
                m++;
            }
        }

        if(m > 0){
            printf("ACHEI\n");
        } else{
            printf("NAO ACHEI\n");
        }

        m = 0;
    }


    return 0;
}