#include <stdio.h>

int main(){
    int i, j, n, M[1000][1000];

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &M[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        printf("%d\n", M[i][n-1-i]);
    }

    return 0;
}