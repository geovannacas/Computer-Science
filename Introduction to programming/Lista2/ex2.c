#include <stdio.h>

int fibonacci(int t1, int t2, int n){
    int i, sum = 0, sum2 = 0, sum3 = 0;

    for(i = 1; i <= n; i++){
        if(i == 1){
            sum = t1;
        } else if(i == 2){
            sum = t2;
        } else if(i == 3){
            sum = t1 + t2;
            sum2 = sum;
        } else if(i == 4){
            sum = t2 + sum2;
            sum3 = sum2;
            sum2 = sum; 
        } else {
            sum = sum3 + sum2;
            sum3 = sum2;
            sum2 = sum; 
        }
    }
    return(sum);
}

int main(){
    int t1, t2, n;

    scanf("%d %d %d", &t1, &t2, &n);

    printf("%d\n", fibonacci(t1, t2, n));

    return 0;
}