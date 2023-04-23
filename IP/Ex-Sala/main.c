#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato {
    char nome[128];
    char tel[16];
    int idade;
};
typedef struct contato Contato;

typedef struct {
    int n;
    Contato * dados;
} Agenda;

#define MOSTRAR 1
#define INSERIR 2
#define EXCLUIR 3
#define BUSCAR  4
#define LER     5
#define SAIR    0


int menu(void) {
    int op;
    printf("%d) Mostrar contatos\n", MOSTRAR);
    printf("%d) Inserir contato\n", INSERIR);
    printf("%d) Excluir contato\n", EXCLUIR);
    printf("%d) Buscar contato\n", BUSCAR);
    printf("%d) Ler contatos\n", LER);
    printf("%d) Sair\n", SAIR);
    scanf("%d", &op);
    return op;
}

void print_contato(Contato c) {
    printf("Nome: %s\n", c.nome);
    printf("Telefone: %s\n", c.tel);
    printf("Idade: %d\n", c.idade);
    printf("\n");
}

void mostrar(Agenda A) {
    int i;
    if(A.n == 0) {
        printf("Agenda vazia!!\n\n");
        return;
    }
    for(i=0;i<A.n;i++) {
        /// imprimir o contato A.dados[0] ... 
        printf("IDX: %d\n", i);
        print_contato( A.dados[i] );
    }
}

void inserir(Agenda * A ) {


    //Professor:
    Contato * ptr = NULL;
    ptr = realloc(A->dados, (A->n+1) * sizeof(Contato));
    if(ptr == NULL) {
        printf("Não foi possível inserir um novo contato por questoes de memoria\n");
        return;
    }

    A->dados = ptr;
    (A->n)++;

    printf("Nome de contato: ");
    scanf("%*c%[^\n]%*c", A->dados[A->n-1].nome);
    printf("Insira o telefone: ");
    scanf("%[^\n]", A->dados[A->n-1].tel);
    printf("Insira a idade: ");
    scanf("%d", &A->dados[A->n-1].idade);

    // Eu:

   /* Contato cont;
    int tamanhoNovo;
    /// adicionar contato

    printf("Insira um nome: ");
    scanf("%s", cont.nome);
    printf("Insira um telefone: ");
    scanf("%s", cont.tel);
    printf("Insira uma idade: ");
    scanf("%d", &cont.idade);
    
    tamanhoNovo = A->n+1;
    A->dados = (Contato*) realloc(A->dados, tamanhoNovo * sizeof(Contato));
    A->dados[A->n] = cont;
    A->n++; */
} 

void excluir_indice( Agenda * A, int idx){

    if( idx < 0 || idx > A->n-1){
        printf("Indice valido\n");
        return;
    }

    for( ; idx < A-> n-1; idx++){
        A->dados[idx] = A->dados[idx+1];
    }

    A->dados = (Contato *) realloc(A->dados, (A->n-1) * sizeof(Contato));
    (A->n)--;
}

void excluir( Agenda * A ){
    int idx;
    printf("Digite o indice: ");
    scanf("%d", &idx);

    excluir_indice(A, idx);
}

void buscar( Agenda A ){
    char str[64];
    int i;
    char *  end = NULL;
    printf("Digite a string de busca: ");
    scanf("%*c%[^\n]", str);

    for(i = 0; i<A.n; i++){
        end = strstr(A.dados[i].nome, str);
        if( end !=  NULL ){
            printf("------ IDX: %d ------\n", i);
            print_contato(A.dados[i]);
        }
    }
}

void ler ( Agenda A ){

}

int main() {
    int op;
    Agenda A = { .n = 0, .dados = NULL };
    // Contato c = {.nome = "Joao", .tel = "62 98888 8888", .idade = 18};
    // A.n = 1;
    // A.dados = &c;
    while(1) {
        op = menu();
        if(op == SAIR) {
            break;
        }
        switch(op) {
            case MOSTRAR:
                printf("Apresentando lista de contatos\n");
                mostrar(A);
                break;
            case INSERIR:
                printf("Inserindo contato\n");
                inserir(&A);
                break;
            case EXCLUIR:
                printf("Excluindo contato\n");
                excluir(&A);
                break;
            case BUSCAR:
                printf("Buscando dados...\n");
                buscar(A);
                break;
            case LER:
                printf("Iniciando a leitura dos dados...\n");
                // ler(A);
                break;
            default:
                printf("Opcao invalida!!\n");
        }
    }

    return 0;
}

