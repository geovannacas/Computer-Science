#include <stdio.h>

typedef struct
{
    char nome[50];
    char curso[50];
    int matricula;
} Aluno;


int main(){
    Aluno aluno[2];

    for(int i = 0; i < 2; i++){
        printf("Informe a matrícula:\n");
        scanf("%d", &aluno[i].matricula);
        printf("Informe o nome:\n");
        scanf("%s", aluno[i].nome);
        printf("Informe o curso:\n");
        scanf("%s", aluno[i].curso);
    }

    for(int j = 0; j < 2; j++){
        printf("----- Matrícula %d -----\n", aluno[j].matricula);
        printf("Nome: %s\n", aluno[j].nome);
        printf("Curso: %s\n", aluno[j].curso);
    }

    return 0;
}