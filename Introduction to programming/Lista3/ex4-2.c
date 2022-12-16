#include <stdio.h>

#define ND 102
int LED[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int main(){
    int n, resto, cont, i;
    char num[ND];

    scanf("%d", &n);

    while (n--)
    {
        cont = 0;

        i = 0;

        scanf("%s", num);

        while(num[i] != '\0'){
            resto = num[i]-'0';
            cont += LED[resto];
            i++;
        }
        

        printf("%d leds\n", cont);
    }
    

    return 0;
}