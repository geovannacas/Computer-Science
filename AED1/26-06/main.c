#include "tad.h"

int main(){
    Lista lista;
    Inicializar(&lista);
    int valor, num, escolha;

    printf("Quantos valores quer inserir?\n");
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        printf("Digite um valor: ");
        scanf("%d", &valor);
        printf("Escolha: \n(1) Inserir no começo\n(2) Inserir no final\n");
        scanf("%d", &escolha);
        if(escolha == 1){
            InserirComeco(&lista, valor);
        } else if(escolha == 2){
            InserirFim(&lista, valor);
        } else{
            printf("ERRO!\n");
            continue;
        }
    }
    Imprime(&lista);

    printf("Escolha um elemento para buscar: ");
    scanf("%d", &valor);
    if(Buscar(&lista, valor)){
        printf("Ele está na lista.\n");
    } else{
        printf("Ele nao está na lista.\n");
    }
    printf("A lista tem %d elemento(s).\n", Qtd(&lista));

    return 0;
}