#include <stdio.h>
#include <math.h>

int main(void)
{
    int caminho, n, count;
    int kilometragem = 0, l, c;
    int v[100], M[6][6];
    int aux = 0, final;
    float aux2;

    // declaração manual
    M[0][0] = 0;
    M[0][1] = 63;
    M[0][2] = 210;
    M[0][3] = 190;
    M[0][5] = 190;
    M[1][0] = 63;
    M[1][1] = 0;
    M[1][2] = 160;
    M[1][3] = 150;
    M[1][4] = 95;
    M[1][5] = 10;
    M[2][0] = 210;
    M[2][1] = 160;
    M[2][2] = 0;
    M[2][3] = 10;
    M[2][4] = 1;
    M[2][5] = 10;
    M[3][0] = 190;
    M[3][1] = 150;
    M[3][2] = 10;
    M[3][3] = 0;
    M[3][4] = 10;
    M[3][5] = 20;
    M[4][0] = 10;
    M[4][1] = 95;
    M[4][2] = 7;
    M[4][3] = 21;
    M[4][4] = 0;
    M[4][5] = 80;
    M[5][0] = 190;
    M[5][1] = 2;
    M[5][3] = 41;
    M[5][4] = 80;
    M[5][5] = 0;

    M[0][4] = -959000; // caminho invalida 1 - gambiarra
    M[5][2] = -959000; // caminho invalida 2 - gambiarra

    scanf("%d", &caminho);
    count = 0;
    while (count < caminho)
    {
        scanf("%d", &v[count]);
        count++;
        aux++;
    }

    for (count = 0; count < caminho - 1; count++)
    {
        l = v[count];
        aux++;
        c = v[1 + count];
        kilometragem = kilometragem + M[l][c];
    }

    final = kilometragem;

    if (kilometragem > 0)
    {
        printf("%d\n", final);
    }
    else if (kilometragem == 0)
    {
        printf("%d\n", final);
    }
    else if (kilometragem < 0)
    {
        printf("rota invalida!\n");
    }
    else
    {
        printf("rota invalida!\n");
    }

    return 0;
}