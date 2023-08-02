#include <stdio.h>
#include "tad1.h"

int main(){
    float c;
    printf("Digite o comprimento da aresta do cubo: ");
    scanf("%f", &c);

    Cubo* c1 = criar_cubo(c);

    printf("O comprimento da aresta do cubo é: %.2f\n", comprimento_aresta(c1));
    printf("A area de uma face do cubo é: %.2f\n", area_face(c1));
    printf("A area total das faces do cubo é: %.2f\n", area_total(c1));
    printf("O volume do cubo é: %.2f\n", volume(c1));
    
    destruir_cubo(c1);

    return 0;
}