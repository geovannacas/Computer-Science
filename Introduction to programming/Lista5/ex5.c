#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    float credito;
    char nome_curso[100];

} Universidade;
 
typedef struct 
{
    char nome_aluno[500];
    int codigo_aluno;
    int num_credito;

} Aluno;

int main(){
    int i,j, n, m;
    float total = 0;

    scanf("%d", &n);

    Universidade uni[30];

    for(i = 0; i < n; i++){
        scanf("%d %f %[^\n]", &uni[i].codigo, &uni[i].credito, uni[i].nome_curso);
        getchar();
    }

    scanf("%d", &m);

    Aluno a[100];
    for(i = 0; i <= m; i++){
        scanf("%[^\n] %d %d", a[i].nome_aluno, &a[i].codigo_aluno, &a[i].num_credito);
        getchar();

        for(j = 0; j <= n; j++){
            if(uni[j].codigo == a[i].codigo_aluno){
                total = uni[j].credito * a[i].num_credito;
                break;
            }
        }
        if(a[i].codigo_aluno != 0) printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2f Mensalidade: %.2f\n", a[i].nome_aluno, uni[j].nome_curso, a[i].num_credito, uni[j].credito, total);
    }


    return 0; 
}