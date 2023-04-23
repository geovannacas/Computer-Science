#include <stdio.h>

int main(){
    float salario;
    int qtd, tipo, etnia;

    scanf("%f %d %d %d", &salario, &qtd, &tipo, &etnia);

    if(salario/qtd <= 1405.5 && tipo == 2 && etnia == 4){
        printf("ALUNO COTISTA (L1)\n");
    } else if(salario/qtd <= 1405.5 && tipo == 2 && etnia != 4){
        printf("ALUNO COTISTA (L2)\n");
    } else if(salario/qtd > 1405.5 && tipo == 2 && etnia == 4){
        printf("ALUNO COTISTA (L3)\n");
    } else if(salario/qtd > 1405.5 && tipo == 2 && etnia != 4){
        printf("ALUNO COTISTA (L4)\n");
    } else{
        printf("ALUNO NAO COTISTA\n");
    }



    return 0;
}