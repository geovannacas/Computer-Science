#include <stdio.h>

int maximo(int v[], int n){
    if(n == 1){
        return v[0];
    } else{
        if(v[n-1] > maximo(v, n-1)){
            return v[n-1];
        } else{
            return maximo(v, n-1);
        }
    }
}

int main(){
    int v[] = {9, 2, 3, 4, 5};
    int n = 5;

    printf("O número máximo é: %d\n",maximo(v, n));

    return 0;
}