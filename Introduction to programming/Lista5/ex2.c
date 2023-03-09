#include <stdio.h>

typedef struct{
    int qtd_disp;
    char nome[50];
    double valor[50];
} Mercado;

typedef struct{
    int num_prod;
    char nome_prod[50];
    int qtd_prod[50];
} Compras;

double produtos(Mercado m1, Compras c1){
    int i, j;
    double total = 0;
    scanf("%d", &m1.qtd_disp);
    for(i = 0; i < m1.qtd_disp; i++){
        scanf("%s %lf", &m1.nome[i], &m1.valor[i]);
    }

    scanf("%d", &c1.num_prod);
    for(i = 0; i < c1.num_prod; i++){
        scanf("%s %d", &c1.nome_prod[i], &c1.qtd_prod[i]);
    }

    for(i = 0; i < m1.qtd_disp; i++){
        for(j = 0; j < c1.num_prod; j++){
            if(m1.nome[i] == c1.nome_prod[j]){
                total += m1.valor[i] * c1.qtd_prod[j];
            }
        }
    }
    return total;
}

int main(){
    int num, i;

    scanf("%d", &num);

    for(i = 0; i < num; i++){
        Mercado m;
        Compras c;
        printf("R$ %.2lf\n", produtos(m, c));
    }

    return 0;
}