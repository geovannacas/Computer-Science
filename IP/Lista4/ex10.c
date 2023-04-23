#include <stdio.h>

int main() {
    int n, m, i, j, k, l;
    scanf("%d %d", &n, &m);
    if (n <= 0 || m <= 0 || n >= 11 || m >= 11) {
        printf("Dimensao invalida\n");
        return 0;
    }
    int mat[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int i_inicio = 0, i_fim = n - 1, j_inicio = 0, j_fim = m - 1;
    while (i_inicio <= i_fim && j_inicio <= j_fim) {
        for (j = j_inicio; j <= j_fim; j++) {
            printf("%d ", mat[i_inicio][j]);
        }
        for (i = i_inicio + 1; i <= i_fim; i++) {
            printf("%d ", mat[i][j_fim]);
        }
        if (i_inicio < i_fim && j_inicio < j_fim) {
            for (j = j_fim - 1; j > j_inicio; j--) {
                printf("%d ", mat[i_fim][j]);
            }
            for (i = i_fim; i > i_inicio; i--) {
                printf("%d ", mat[i][j_inicio]);
            }
        }
        i_inicio++;
        i_fim--;
        j_inicio++;
        j_fim--;
    }
    printf("\n");
    return 0;
}
