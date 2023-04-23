#include <stdio.h>

int main()
{
    int casos_de_teste, num_fracoes, i, j, k;
    scanf("%d", &casos_de_teste);
    for (k = 1; k <= casos_de_teste; k++)
    {
        scanf("%d", &num_fracoes);

        int numeradores[num_fracoes];
        int denominadores[num_fracoes];

        for (i = 0; i < num_fracoes; i++)
        {
            scanf("%d/%d", &numeradores[i], &denominadores[i]);
        }

        printf("Caso de teste %d\n", k);
        int igual = 0;
        for (i = 0; i < num_fracoes; i++)
        {
            for (j = i + 1; j < num_fracoes; j++)
            {
                if (numeradores[i] * denominadores[j] == numeradores[j] * denominadores[i])
                {
                    printf("%d/%d equivalente a %d/%d\n", numeradores[i], denominadores[i], numeradores[j], denominadores[j]);
                    igual = 1;
                }
            }
        }
        if (igual == 0)
        {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
    }
    return 0;
}