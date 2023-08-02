#include "tad.h"

void Inicializar(TipoLista *Lista){
    Lista->Primeiro = 0;
    Lista->Ultimo = Lista->Primeiro;
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

TipoLista Concatenar(TipoLista Lista1, TipoLista Lista2){
    TipoLista ListaConcatenada;
    Inicializar(&ListaConcatenada);

    int i;
    for(i = Lista1.Primeiro; i < Lista1.Ultimo; i++){
        Insere(Lista1.Item[i], &ListaConcatenada);
    }

    for(i = Lista2.Primeiro; i < Lista2.Ultimo; i++){
        Insere(Lista2.Item[i], &ListaConcatenada);
    }

    return ListaConcatenada;
}   