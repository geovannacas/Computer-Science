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

int NumerosPares(TipoLista Lista){
    int Aux, QtdPares = 0;
    int i;

    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++){
        int repetido = 0;

        for(i = Lista.Primeiro; i < Aux; i++){
            if(Lista.Item[i] == Lista.Item[Aux]){
                repetido = 1;
                break;
            }
        }

        if(Lista.Item[Aux] % 2 == 0 && !repetido){
            QtdPares++;
        }
    }

    return QtdPares;
}