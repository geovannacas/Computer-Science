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

void Remover(int n, TipoLista *Lista){
    int Aux;
    if(n > Lista->Ultimo || n <= 0){
        printf("Não foi possível remover os elementos da lista: ERRO - Número de elementos inválido\n");
    } else if(n == Lista->Ultimo){
        Inicializar(Lista);
        printf("Foi removido os %d primeiros elementos: A lista está vazia.\n", n);
    } else{
        for(Aux = n; Aux < Lista->Ultimo; Aux++){
            Lista->Item[Aux-n] = Lista->Item[Aux];
        }
        Lista->Ultimo -= n;
        printf("Foi removido os %d primeiros elementos:\n", n);
        Imprime(*Lista);
    }
}