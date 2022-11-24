#include <stdio.h>

int main(){
    int i, n, atual, before, cont=1, maxx=0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &atual);

        if(i != 0){
            if(atual > before){
                cont++;
            } 
            else{
                if(maxx < cont){
                    maxx = cont;
                }
                cont = 1;
            }
        }
        before = atual;
    }

    if(maxx < cont){
        maxx = cont;
    }

    printf("O comprimento do segmento crescente maximo e: %d\n", maxx);

    return 0;
}