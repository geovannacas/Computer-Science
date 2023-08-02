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

int Media(TipoLista Lista){
    int Aux, media = 0;

    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
        media+= Lista.Item[Aux];

    return media/(Aux);
}