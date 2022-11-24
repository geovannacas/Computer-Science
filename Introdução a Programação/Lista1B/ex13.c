#include <stdio.h>

int main(){
    int n, i, x, j=1;

    scanf("%d", &n);

    for(i = 1; i <= n; i++){

        printf("%d*%d*%d = ", i, i, i);

        if(i==1){
            j = i;
        }

        x = i; 

        while(x != 0){
            if(j % 2 != 0){
                printf("%d", j);

                j+=2;

                x--;    
                
                if(x == 0){
                    break;
                }
                
                printf("+");
            }
        }

        printf("\n");
    }

    return 0;
}