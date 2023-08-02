#include <stdio.h>
#include <stdlib.h>
#include "tad1.h"

// Inicializar
void Inicializar(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}
// Verificar lista vazia
int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}
// Inserir elemento
void Insere(int x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void InsereEmP(int x, TipoApontador p,TipoLista *Lista){
}

// Retirar elemento
void Retira(TipoApontador p, TipoLista *Lista)
{
    // Observacao: o item a ser retirado e o seguinte ao apontado por p
    int valor;
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL)
    {
        printf(" Erro, lista vazia ou posicao nao existe\n");
        return;
    } else{
        q = p->Prox;
        valor = q->Item;
        p->Prox = q->Prox;
        if (p->Prox == NULL)
            Lista->Ultimo = p;
        free(q);
    }
}
// Imprimir elementos
void Imprime(TipoLista Lista)
{
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while (Aux != NULL)
    {
        printf("%d\n", Aux->Item);
        Aux = Aux->Prox;
    }
}

// Conta quantos valores impares existem na lista

int Conta_Impares(TipoLista Lista){
    TipoApontador i;
    int impares = 0;
    i = Lista.Primeiro->Prox;
    while (i != NULL)
    {
        if(i->Item % 2 != 0){
            impares++;
        }
        i = i->Prox;
    }
    return impares;
}

// Retorna o menor valor da lista

int Menor_Valor(TipoLista Lista){
    TipoApontador i;
    int menor;
    i = Lista.Primeiro->Prox;
    menor = Lista.Primeiro->Prox->Item;
    while (i != NULL)
    {
        if(i->Item < menor){
            menor = i->Item;
        }
        i = i->Prox;
    }
    return menor;
}