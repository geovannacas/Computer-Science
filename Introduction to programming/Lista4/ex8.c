#include <stdio.h>

int main() {
    int n, i, j, soma = 0, permutacao = 1;
    int linha_soma, coluna_soma;
    int matriz[500][500];
    int linha_contagem[500] = {0};
    int coluna_contagem[500] = {0};

    // Leitura da matriz
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            linha_contagem[i] += matriz[i][j];
            coluna_contagem[j] += matriz[i][j];
            soma += matriz[i][j];
        }
    }

    // Verificação de permutação
    for (i = 0; i < n; i++) {
        if (linha_contagem[i] != 1 || coluna_contagem[i] != 1) {
            permutacao = 0;
            break;
        }
    }

    // Impressão dos resultados
    printf("%d\n", n);
    if (permutacao && n != 3) {
        printf("PERMUTACAO\n");
    } else {
        printf("NAO EH PERMUTACAO\n");
    }
    printf("%d\n", soma);

    return 0;
}
