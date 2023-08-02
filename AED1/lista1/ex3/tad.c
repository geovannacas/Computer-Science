#include "tad.h"


void Inicializar(TipoLista *Lista){
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(int x, TipoLista *Lista){
    if(Lista->Ultimo >= MAXTAM){
        printf("A lista está lotada\n");
    } else{
        Lista->Item[Lista->Ultimo] = x;
        Lista->Ultimo++;
    }
}

void Imprime(TipoLista Lista){
    int Aux;
    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++){
        if(Aux < Lista.Ultimo - 1){
            printf("%d, ", Lista.Item[Aux]);
        } else{
            printf("%d\n", Lista.Item[Aux]);
        }
    }
}

void MaiorElemento(TipoLista Lista, int *posicao, int *valor){
    
    if(Vazia(Lista)){
        printf("Não foi possível buscar a posição e o valor do maior elemento da lista (Lista vazia).\n");
    } else{
        int Aux;

        for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++){
            if(Lista.Item[Aux] > Lista.Item[Aux+1]){
                *posicao = Aux;
            } else{
                *posicao = Aux+1;
            }
        }

        *valor = Lista.Item[*posicao];
        printf("O maior elemento da lista tem:\nValor = %d\nPosição = %d\n", *valor, *posicao);
    }
}