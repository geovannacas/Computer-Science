#include <stdio.h>

int main(){
    int M[10][10];
    int l = 0, c = 0, i, j, num, n;

    do
    {
        scanf("%d", &l);
    } while (l <= 0 || l > 10);

    do
    {
        scanf("%d", &c);
    } while (c <= 0 || c > 10);

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &M[i][j]);
        }
    }

    for (i = 0; i < l; i++){
        n = i+1;
        printf("linha %d:   ", n);
        for (j = 0; j < c; j++){
            if(j == c-1){
                printf("%d\n", M[i][j]);
            } else{
                printf("%d,", M[i][j]);
            }
        }
    }

    return 0;
}