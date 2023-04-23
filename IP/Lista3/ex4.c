#include <stdio.h>

int LED[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int main(){
    int n, num, resto, cont;

    scanf("%d", &n);

    while (n--)
    {
        cont = 0;
        scanf("%d", &num);
        if(num == 0){
            cont = LED[0];
        } else{
            while(num > 0){
                resto = num%10;
                cont += LED[resto];
                num = num/10;
            }
        }

        printf("%d leds\n", cont);
    }
    

    return 0;
}