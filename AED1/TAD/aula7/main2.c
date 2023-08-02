#include <stdio.h>
#include "tad2.h" 

int main()
{
    float x1, y1, x2, y2, z1, z2, d;
    Ponto *p, *q;
    printf("Digite as coordenadas x, y e z para o ponto 1: ");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("Digite as coordenadas x, z e y para o ponto 2: ");
    scanf("%f %f %f", &x2, &y2, &z2);
    p = criar_ponto(x1, y1, z1);
    q = criar_ponto(x2, y2, z2);
    d = calcular_distancia(p, q);
    acessar_ponto(p, &x1, &y1, &z1);
    acessar_ponto(q, &x2, &y2, &z2);
    printf("Distancia entre os pontos (%.2f, %.2f, %.2f) e (%.2f, %.2f, %.2f) = %.5f.\n", x1, y1, z1, x2, y2, z2, d);
    liberar_ponto(p);
    liberar_ponto(q);
    return (0);
}
