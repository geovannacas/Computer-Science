#include <stdio.h>

int main(){
    int x, aux, reverso;

    scanf("%d", &x);

    if(x > 99999){
        printf("NUMERO INVALIDO\n");
    }else {
        aux = x;
        reverso = 0;

        while (aux != 0) {
            reverso = reverso * 10 + aux % 10;  
            aux = aux / 10;                     
        }
        
        if(reverso == x){
            printf("PALINDROMO\n");
        }else{
            printf("NAO PALINDROMO\n");
        }
    }

    return 0;
}