#include <stdio.h>

int main(){
    int n, m, i, j;
    scanf("%d %d", &m, &n);

    for(i=2; i<= m; i++){
        for(j=1; j<= n; j++){
            if(i == j){
                break;
            } 
            if(i != j){
                if(i-j == 1 || j == n){
                    printf("(%d,%d)", i, j);
                } else{
                    printf("(%d,%d)-", i, j);
                }
            } 
        }
        printf("\n");
    }

    return 0;
}