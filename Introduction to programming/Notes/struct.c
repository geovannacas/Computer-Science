#include <stdio.h>

struct  circulo
{
    double x; // posicao x no plano 2D
    double y; // posicao y no plano 2D
    double raio;  // tamanho do raio
};

struct circulo cria_circulo(void){
    struct  circulo tmp;
    scanf("%lf %lf %lf", &(tmp.x), &(tmp.y), &(tmp.raio));
    return tmp;
}

void print_circulo( struct circulo c ) {
    printf("(%.2lf, %.2lf) - %.2lf\n", c.x, c.y, c.raio);
}

int main(){
    struct circulo A = {0}; // zera todos os elementos
    struct circulo B = {.x = 1, .y = 3, .raio = 7};
    struct circulo C = {1, 3, 7}; // inicializa na ordem de declaracao
    struct circulo D; // struct sem inicializacao

    A = cria_circulo();
    print_circulo(A);

    return 0;
}