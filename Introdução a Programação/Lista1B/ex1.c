#include <stdio.h>
    
int main(){
    int n;
    float temp, C;
    
    scanf("%d", &n);
    
    while(n > 0){
        scanf("%f", &temp);
    
        C = (5*(temp-32))/9;
    
        printf("%.2f FAHRENHEIT EQUIVALE A %.2f CELSIUS\n", temp, C);
            
        n--;
    }

    return 0;
}