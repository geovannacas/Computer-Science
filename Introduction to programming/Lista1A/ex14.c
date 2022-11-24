#include <stdio.h>

int main(){
    int i;
    float a, b, c, n;

    n = 0;
    
    scanf("%d", &i);
    scanf("%f %f %f", &a, &b, &c);
 
    if(a > b){
        n = b;
        b = a;
        a = n;
    }
    if(a > c){
        n = c;
        c = a;
        a = n;
    }
    if(b > c){
        n = c;
        c = b;
        b = n;
    }

    if(i == 1){
        printf("%.2f %.2f %.2f\n", a, b, c);
    } else if(i == 2){
        printf("%.2f %.2f %.2f\n", c, b, a);
    } else if(i == 3){
        printf("%.2f %.2f %.2f\n", b, c, a);
    }
    
    return 0;
}