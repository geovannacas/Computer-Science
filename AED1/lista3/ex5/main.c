#include "tad.h"

int main(){
    Fila fila;
    Inicializar(&fila);

    int id, capacidade;
    char nome[50], tipo[50];

    int escolha;

    do{
        printf("-- Menu --\n1. Listar o número de aviões aguardando na fila de espera\n2. Autorizar a decolagem do primeiro avião da fila\n3. Adicionar um avião à fila de espera\n4. Listar todos os aviões na fila de espera\n5. Listar as características do primeiro avião da fila\n6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("O número de aviões aguardando é: %d\n", NumeroAviao(&fila));
            break;
        case 2:
            No* autorizado = AutorizarDecolagem(&fila);
            if (autorizado != NULL)
                printf("Avião autorizado -> ID: %d - Nome: %s\n", autorizado->aviao.id, autorizado->aviao.nome);
            break;
        case 3:
            printf("Digite o número identificador: ");
            scanf("%d", &id);
            printf("Digite o nome: ");
            scanf("%s", nome);
            printf("Digite o tipo: ");
            scanf("%s", tipo);
            printf("Digite a capacidade: ");
            scanf("%d", &capacidade);
            AdicionarAviao(&fila, id, nome, capacidade, tipo);
            break;
        case 4:
            ListarFila(&fila);
            break;
        case 5:
            ImprimePrimeiro(&fila);
            break;
        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while(escolha != 6);


    return 0;
}