
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad2.h"

struct ponto
{
    float x;
    float y;
    float z;
};

Ponto *criar_ponto(float novo_x, float novo_y, float novo_z)
{
    Ponto *novo_ponto = (Ponto *)malloc(sizeof(Ponto));
    if (novo_ponto != NULL)
    {
        novo_ponto->x = novo_x;
        novo_ponto->y = novo_y;
        novo_ponto->z = novo_z;
    }
    return (novo_ponto);
}

void liberar_ponto(Ponto *p)
{
    if (p != NULL)
    {
        free(p);
    }
}

void acessar_ponto(Ponto *p, float *x, float *y, float *z)
{
    if (p != NULL)
    {
        *x = p->x;
        *y = p->y;
        *z = p->z;
    }
}

void atribuir_ponto(Ponto *p, float novo_x, float novo_y, float novo_z)
{
    if (p != NULL)
    {
        p->x = novo_x;
        p->y = novo_y;
        p->z = novo_z;
    }
}

float calcular_distancia(Ponto *ponto_1, Ponto *ponto_2)
{
    float dist_x = ponto_1->x - ponto_2->x;
    float dist_y = ponto_1->y - ponto_2->y;
    float dist_z = ponto_1->z - ponto_2->z;
    return (sqrt((dist_x * dist_x) + (dist_y * dist_y) + (dist_z * dist_z)));
}