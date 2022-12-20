#include <stdio.h>
#include <math.h>

int next_power( int n, int p );

int main(){
    int n, p;
    
    scanf("%d %d", &n, &p);
    
    next_power(n,p);
    
    return 0;
}

int next_power(int n, int p){
    int i = 0, before = 0, total = 0;
    
    if(n == 0 && p != 0){
        printf("%d -> 0^%d = 0\n", n, p);
    } else if(p == 0){
        printf("%d -> 0^%d = 1\n", n, p);
    } else{
        do{
            before = total;
            i++;
            total = pow(i, p);
        } while(total <= n*2);
        
        printf("%d -> %d^%d = %d\n", n, i-1, p, before);
    }
    
    return(before);
}
