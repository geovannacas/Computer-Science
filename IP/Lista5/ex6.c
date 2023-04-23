#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} DataNasc;

typedef struct{
    int matricula;
    DataNasc data_nasc;
    char nome[200];

} Aluno;

int ComparaDataNasc(DataNasc *data1, DataNasc *data2){
    if(data1->ano < data2->ano){
        return 1;
    } else if(data1->ano == data2->ano){
        if (data1->mes < data2->mes) {
            return 1;
        } else if (data1->mes == data2->mes) {
            if (data1->dia <= data2->dia) {
                return 1;
            }
        }
    }
    return 0;
}

void Ordena(Aluno *alunos, int n){
    int i, j;
    Aluno temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (ComparaDataNasc(&alunos[i].data_nasc, &alunos[j].data_nasc) != 0) {
                temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
}


int main(){
    int n, i;
    Aluno *alunos;

    scanf("%d", &n);

    alunos = (Aluno*) malloc(n * sizeof(Aluno));

    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d %[^\n]", &alunos[i].matricula, &alunos[i].data_nasc.dia, &alunos[i].data_nasc.mes, &alunos[i].data_nasc.ano, alunos[i].nome);
    }

    Ordena(alunos, n);

    for (i = 0; i < n; i++) {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", alunos[i].matricula, alunos[i].nome, alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
    }

    free(alunos);

    return 0;
}