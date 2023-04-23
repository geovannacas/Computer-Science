#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define P 100

int main(void)
{
    int lat2, n, aux = 0;
    int lat1;
    int l, c, borda;
    char lateral, preenche_fundo;
    char m[P][P];

    scanf("%d %c %c", &n, &lateral, &preenche_fundo);
    getchar();
    if (n < 1)
    {
        printf("Dimensao invalida!\n"); // neutro ou neg
    }
    else if (n % 2 == 0)
    {
        printf("Dimensao invalida!\n"); // par
    }
    else
    {

        borda = ((n - 1) / 2);
        lat2 = borda;
        aux = 0;

        for (l = 0; l < n; l++)
        {

            if (l < ((n - 1) / 2))
            {
                c = 0;
                for (;;)
                {
                    if (c == n)
                    {
                        break;
                    }
                    else
                    {
                        if (c == lat2)
                        {
                            m[l][c] = lateral;
                        }
                        if (c == borda)
                        {
                            m[l][c] = lateral;
                        }
                        if (c > lat2 || c < borda || c > lat2)
                        {
                            m[l][c] = ' '; // printa os espaços
                        }
                        if (c > borda && c < lat2)
                        {
                            m[l][c] = preenche_fundo;
                            aux++;
                        }
                    }
                    c++;
                    if (c == n)
                    {
                        break;
                    }
                    if (n == c)
                    {
                        break;
                    }
                }
            }
            else
            {
                c = 0;
                aux = 0;
                for (;;)
                {

                    if (c == n)
                    {
                        break;
                    }
                    while (1)
                    {
                        /*if ( c == borda || c == lat2){
                         m[l][c] = lateral;*/
                        break;
                    }
                    if (c == borda || c == lat2)
                    {
                        m[l][c] = lateral;
                    }
                    else if (c > borda && c < lat2)
                    {
                        m[l][c] = preenche_fundo;
                    }
                    else
                    {
                        m[l][c] = ' ';
                    }
                    if (c == n)
                    {
                        break;
                    }

                    c = c + 1;
                    aux++;
                }
            }

            if (l < (n - 1) / 2)
            {
                borda--;
                lat2++;
            }
            else if (l >= ((n - 1) / 2))
            {
                lat2--;
                borda++;
                aux++;
            }
        }

        for (l = 0; l < n; l++)
        {
            c = 0;

            while (c < n)
            {

                printf("%c ", m[l][c]);
                c++;
            }

            printf("\n");
        }
    }

    return 0;
}
