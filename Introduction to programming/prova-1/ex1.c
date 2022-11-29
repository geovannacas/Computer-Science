#include <stdio.h>

int main(){
    int cont, num, i;
    int j = 0, k = 0;
    int temp = 0, start = 0, end = 0, maxx = 0, z;

    scanf("%d", &cont);

    scanf("%d", &num);

    for(i = 1; i < cont; i++){
        temp = num;

        scanf("%d", &num);

        j++;

        if(maxx <= k){
            maxx = k;
            end = j;
        }

        if(maxx <= k){
            z = maxx;
            start = end - z; 
            start++;
        }

        if(temp == num){
            if(k == 0){
                k++;
            }

            k++;

        } 
        else {
            k = 0;
        }
    }

    if(maxx <= k){
        maxx = k;
        end = j+1;
    }

    if(maxx <= k){
        z = maxx;
        start = end - z; 
        start++;
    }

    if(maxx == 0){
        printf("SEM SEGMENTO IGUAL\n"); 
    } 
    else{
        printf("%d(%d->%d)\n", maxx, start, end); 
    }

    return 0;
}