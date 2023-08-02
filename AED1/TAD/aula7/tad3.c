#include <stdio.h>
#include <stdlib.h>
#include "tad3.h"

struct retangulo{
    int largura;
    int altura;
};

Retangulo* criar_retangulo(int largura_entry, int altura_entry){
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    if(r != NULL){
        r->largura = largura_entry;
        r->altura = altura_entry;
    }
    return r;
}

void apresentar(Retangulo* r){
    if (r != NULL)
    {
        printf("Largura: %d\n", r->largura);
        printf("Altura: %d\n", r->altura);
    }
}

int perimetro(Retangulo* r){
    return r->largura * 2 + r->altura *2;
}

int area(Retangulo* r){
    return r-> largura * r->altura;
}

void liberar(Retangulo* r){
    if (r != NULL){
        free(r);
    }
}

