#include <stdio.h>

int main() {
    int i, j, n, m, a[1000][1000], menor = 1001, maior = -1, countMenor = 0, countMaior = 0;
    double freqMenor, freqMaior;

    // Lê a entrada
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] < menor) {
                menor = a[i][j];
            }
            if (a[i][j] > maior) {
                maior = a[i][j];
            }
        }
    }

    // Conta a frequência do menor e do maior valores
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == menor) {
                countMenor++;
            }
            if (a[i][j] == maior) {
                countMaior++;
            }
        }
    }

    // Calcula a frequência do menor e do maior valores
    freqMenor = (double) countMenor / (n * m) * 100;
    freqMaior = (double) countMaior / (n * m) * 100;

    // Imprime a saída
    printf("%d %.2lf%%\n", menor, freqMenor);
    printf("%d %.2lf%%\n\n", maior, freqMaior);

    return 0;
}
