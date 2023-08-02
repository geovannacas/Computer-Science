#include <stdio.h>

float media(float x, float y, float z, char letra){
    if(letra == 'A'){
        return (x+y+z)/3;
    } else if(letra == 'P'){
        return ((x*5)+ (y*3) + (z*2))/10;
    }
}

int main(){
    float x, y, z;
    char letra;

    printf("Digite as 3 notas + a letra A ou P:\n");
    scanf("%f %f %f %c", &x, &y, &z, &letra);

    printf("A média é: %.2f\n", media(x, y, z, letra));

    return 0;
}