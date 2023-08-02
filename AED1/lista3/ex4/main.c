#include "tad.h"

int main(){
    Fila fila;
    Inicializar(&fila);

    int processo, p, tempo;

    int escolha;

    do{
        printf("-- Menu --\n1. Adicionar processo\n2. Retirar processo com o maior tempo de espera\n3. Imprimir a lista de processo\n4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("Digite o número do processo: ");
            scanf("%d", &processo);
            tempo = 0;
            Enfileirar(&fila, processo);
            AddTempo(&fila);
            break;
        case 2:
            No* processoRemovido = Desenfilerar(&fila);
            if (processoRemovido != NULL)
                printf("Processo removido: ID %d\n", processoRemovido->processo);
            break;
        case 3:
            Imprime(&fila);
            break;
        case 4:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while(escolha != 4);


    return 0;
}