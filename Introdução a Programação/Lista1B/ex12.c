#include <stdio.h>
#include <math.h>

int main(){
    int n, cateto1, cateto2, i;
    float hipotenusa;


    scanf("%d" , &n);

    for(i = 1; i <= n; i++){
        for(cateto1 = 1; cateto1 <= i; cateto1++){
            for(cateto2 = 1; cateto2 <= i; cateto2++){
                hipotenusa = sqrt(cateto1*cateto1 + cateto2*cateto2);
                if(hipotenusa == i){
                    if(cateto1 <= cateto2 ){
                        printf("hipotenusa = %d, catetos %d e %d\n", i, cateto1, cateto2);
                    }       
                }
            }
        }
    }

    return 0;
}