#include "tad.h"

No *Aloca(){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo -> prox = NULL;
    return novoNo;
}

Lista *Inicializar() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));

    lista->inicio = NULL;
    lista->fim = lista->inicio;

    return lista;
}

int Tamanho(Lista *lista){
    int tamanho = 0;
    No* i = lista->inicio;

    while (i != NULL){
        tamanho++;
        i = i->prox;
    }    

    return tamanho;
}

void Insere(int x, int posicao, Lista *lista){
    No *p = Aloca();
    int tamanho = Tamanho(lista);
    p->Item = x;

    if(posicao <= 0 || posicao > tamanho+1){//Posição Inválida
        printf("Posição não existe\n");
        return;

    } 
    if(tamanho == 0){ // Inserir em lista vazia
        lista->inicio = p;
        lista->fim = p;
        return;
    }
    
    if(posicao == 1){//Inserir Começo
        p->prox = lista->inicio;
        lista->inicio = p;

    } else if(posicao == tamanho+1){//Inserir Fim
        lista->fim->prox = p;
        lista->fim = p;

    } else{//Inserir Meio
        No *i = lista->inicio;
        int j = 0;

        while(j != posicao-1){
            i = i->prox;
            j++;
        }

        p->prox = i->prox;
        i->prox = p;
    }
}

Lista *Vetor(int vetor[], int tamanho){
    Lista *lista;
    lista = Inicializar();

    for(int i = 0; i < tamanho; i++){
        Insere(vetor[i], i+1, lista);
    }

    return lista;
}

void Imprime(Lista *lista){
    if(lista->inicio == NULL){
        printf("Lista Vazia\n");
    } else{
        No *i = lista->inicio;
        int x = 1;

        printf("O vetor tem os seguintes elementos:\n");
        while(i != NULL){
            printf("%d) %d\n", x, i->Item);
            i = i->prox;
            x++;
        }
    }
}

