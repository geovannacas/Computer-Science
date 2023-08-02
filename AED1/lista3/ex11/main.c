#include "tad.h"

int main(){
    int num;
    Fila filapar;
    Fila filaimpar;
    InicializarFila(&filapar);
    InicializarFila(&filaimpar);
    Pilha pilha;
    InicializarPilha(&pilha);

    printf("Digite um número (0 para sair): ");
    scanf("%d", &num);

    while (num != 0)
    {
        if(num % 2 == 0){
            Enfileirar(&filapar, num);
        } else{
            Enfileirar(&filaimpar, num);
        }

        printf("Digite um número (0 para sair): ");
        scanf("%d", &num);
    }
    
    while(!FilaVazia(&filaimpar) || !FilaVazia(&filapar))
    {
        if(!FilaVazia(&filaimpar)){
            int x = Desenfilerar(&filaimpar);

            if(x > 0){
                Empilhar(&pilha, x);
            } else{
                Desempilhar(&pilha);
            }
        }


        if(!FilaVazia(&filapar)){
            int y = Desenfilerar(&filapar);    

            if(y > 0){
                Empilhar(&pilha, y);
            } else{
                Desempilhar(&pilha);
            }    
        }
    }

    if (!PilhaVazia(&pilha))
    {
        ImprimePilha(&pilha);
    } else{
        printf("O conteúdo da pilha está vazio.\n");
    }

    return 0;
}