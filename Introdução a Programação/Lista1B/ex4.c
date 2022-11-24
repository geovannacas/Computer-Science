#include <stdio.h>

int main(){
   
    int x;
    double soma, total, i=1;
    
    scanf("%d", &x);
    
    if(x > 0){
        for(i = 1; i <= x; i++){
            total = 1/i;
            soma += total;
        }

        printf("%.6lf\n", soma);
    } else{
        printf("Numero invalido!\n");
    }

    return 0;
}