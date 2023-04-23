#include <stdio.h>

int main(){
    int T, i, A, B, x, c, d, u, total=0, c1, d1, u1, x1, total1=0;

    scanf("%d", &T);
    
    for(i = 0; i < T; i++){
        scanf("%d %d", &A, &B);

        u = (A/100);
        x = A%100;
        d = (x/10)*10;
        c = (x%10)*100; 

        u1 = (B/100);
        x1 = B%100;
        d1 = (x1/10)*10;
        c1 = (x1%10)*100; 

        total = c+d+u; 
        total1 = c1+d1+u1;

        if(total > total1){
            printf("%d\n", total);
        } else{
            printf("%d\n", total1);
        }
    }
    return 0;
}