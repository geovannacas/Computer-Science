#include "tad.h"

int main() {
    int N = 5;

    Aluno exemplos[] = {
        {123, 8.5},
        {456, 7.2},
        {789, 9.0},
        {234, 6.8},
        {567, 8.0}
    };
    
    
    quickSort(alunos, 0, N - 1);
    printf("Alunos ordenados por nota:\n");
    for (int i = 0; i < N; i++) {
        printf("Matrícula: %u, Nota: %.2f\n", alunos[i].Matricula, alunos[i].Nota);
    }

    printf("\n");

    mergeSort(alunos, 0, N - 1);
    printf("Alunos ordenados por matrícula:\n");
    for (int i = 0; i < N; i++) {
        printf("Matrícula: %u, Nota: %.2f\n", alunos[i].Matricula, alunos[i].Nota);
    }

    free(alunos);

    return 0;
}
