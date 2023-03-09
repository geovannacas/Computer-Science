#include <stdio.h>

typedef struct {
    int num;
    int den;
} Fracao;

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b);
    }
}

int sao_equivalentes(Fracao f1, Fracao f2) {
    int mdc1 = mdc(f1.num, f1.den);
    int mdc2 = mdc(f2.num, f2.den);
    return (f1.num / mdc1 == f2.num / mdc2 && f1.den / mdc1 == f2.den / mdc2);
}

int main() {
    int n, t, m, i, j;
    Fracao fracoes[50];

    scanf("%d", &n);

    for (t = 1; t <= n; t++) {
        scanf("%d", &m);

        for (i = 0; i < m; i++) {
            scanf("%d/%d", &fracoes[i].num, &fracoes[i].den);
        }

        printf("Caso de teste %d\n", t);

        int encontrou_equivalentes = 0;

        for (i = 0; i < m - 1; i++) {
            for (j = i + 1; j < m; j++) {
                if (sao_equivalentes(fracoes[i], fracoes[j])) {
                    printf("%d/%d equivalente a %d/%d\n", fracoes[i].num, fracoes[i].den, fracoes[j].num, fracoes[j].den);
                    encontrou_equivalentes = 1;
                }
            }
        }

        if (!encontrou_equivalentes) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
    }

    return 0;
}
