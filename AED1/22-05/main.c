#include "tad.h"

int main(){
    Pilha pilha;
    Produto produto;
    criar_pilha(&pilha);

    int num;

    do{

    printf("Digite:\n");
    printf("1 - Adicionar um produto ao estoque\n");
    printf("2 - Vender um produto do estoque\n");
    printf("3 - Exibir um produto no topo da pilha\n");
    printf("4 - Exibir a quantidade total de produtos em estoque\n");
    printf("5 - Sair do programa\n");
    scanf("%d", &num);
    

    switch (num)
    {
    case 1:
        printf("Digite o nome do produto:\n");
        scanf("%s", produto.nome);
        printf("Digite o código do produto:\n");
        scanf("%d", &produto.codigo);
        printf("Digite a quantidade de produtos:\n");
        scanf("%d", &produto.quantidade);
        
        empilha(&pilha, produto);
        break;
    case 2:
        desempilha(&pilha);
        break;
    case 3:
        imprime_topo(&pilha);
        break;
    case 4:
        int qtd = qtd_estoque(&pilha);
        printf("Tem %d produtos no estoque.\n", qtd);
        break;
    case 5:
        break;
    default:
        printf("Insira um valor válido.\n");
        break;
    }
    }
    while(num != 5);


    return 0;
}