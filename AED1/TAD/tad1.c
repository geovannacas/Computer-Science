#include <stdio.h>
#include <stdlib.h>
#include "tad1.h"

struct cubo{
    float aresta;
};

Cubo* criar_cubo(float aresta_entry){
    Cubo* c = (Cubo*)malloc(sizeof(Cubo*));
    if (c != NULL) {
        c->aresta = aresta_entry;
    }
    return c;
}

void destruir_cubo (Cubo* c) {
    if (c != NULL) {
        free(c);
    }
}

float comprimento_aresta(Cubo* c){
    return c->aresta;
}

float area_face(Cubo* c){
    return c->aresta * c->aresta;
}

float area_total(Cubo* c){
    return 6 * c->aresta * c->aresta;
}

float volume(Cubo* c){
    return c->aresta * c->aresta *c->aresta;
}