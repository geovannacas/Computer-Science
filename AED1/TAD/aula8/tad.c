#include <stdio.h>
#include "tad.h"

#define INICIOARRANJO 1
#define MAXTAM 1000

typedef int TipoChave;
typedef int TipoApontador;

typedef struct
{
    TipoChave Chave;
    /* outros componentes */
} TipoItem;

typedef struct
{
    TipoItem Item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
} /* FLVazia */

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
} /* Vazia */

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo > MAXTAM)
        printf("Lista esta cheia\n");
    else
    {
        Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo++;
    }
} /* Insere */

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if (Vazia(*Lista) || p >= Lista->Ultimo)
    {
        printf(" Erro Posicao nao existe\n");
        return;
    }
    *Item = Lista->Item[p - 1];
    Lista->Ultimo--;
    for (Aux = p; Aux < Lista->Ultimo; Aux++)
        Lista->Item[Aux - 1] = Lista->Item[Aux];
} /* Retira */

void Imprime(TipoLista Lista)
{
    int Aux;
    for (Aux = Lista.Primeiro - 1; Aux <= (Lista.Ultimo - 1); Aux++)
        printf("%d\n", Lista.Item[Aux].Chave);
} /* Imprime */