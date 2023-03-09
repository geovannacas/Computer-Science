#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto {
    double u;
    double x;
    double y;
    double z;
    double norma;
};

// Função para calcular a norma de um ponto
void calcularNorma(struct Ponto *ponto) {
    ponto->norma = sqrt(pow(ponto->u, 2) + pow(ponto->x, 2) + pow(ponto->y, 2) + pow(ponto->z, 2));
}

// Função para comparar os valores das normas de dois pontos
int compararNorma(const void *p1, const void *p2) {
    struct Ponto *ponto1 = (struct Ponto*) p1;
    struct Ponto *ponto2 = (struct Ponto*) p2;
    if (ponto1->norma < ponto2->norma) {
        return -1;
    } else if (ponto1->norma > ponto2->norma) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, i;
    scanf("%d", &n);

    struct Ponto pontos[n];

    // Lê os pontos e calcula as suas normas
    for (i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf", &pontos[i].u, &pontos[i].x, &pontos[i].y, &pontos[i].z);
        calcularNorma(&pontos[i]);
    }

    // Ordena os pontos em ordem crescente de norma
    qsort(pontos, n, sizeof(struct Ponto), compararNorma);

    // Imprime os pontos ordenados com as suas normas
    for (i = 0; i < n; i++) {
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", pontos[i].u, pontos[i].x, pontos[i].y, pontos[i].z, pontos[i].norma);
    }

    return 0;
}
