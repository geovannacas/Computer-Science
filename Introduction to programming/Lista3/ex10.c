#include <stdio.h>

int main()
{
    int n, i, j, maior, menor, num[1050];

    scanf("%d", &n);

    for(i = 0; i<n; i++)
    {
        scanf("%d", &num[i]);
    }

    for(j=0; j<n; j++)
    {
        if(j==0)
        {
            maior = num[j];
            menor = num[j];
        } else
        {
            if(num[j] > maior)
            {
                maior = num[j];
            }
            if(num[j] < menor)
            {
                menor = num[j];
            }
        }
    }

    for(i=0; i<n; i++)
    {
        if(i == n-1)
        {
            printf("%d\n", num[i]);
        } else
        {
            printf("%d ", num[i]);
        }
    }

    for(i=n-1; i>=0; i--)
    {
        if(i == 0)
        {
            printf("%d\n", num[i]);
        } else
        {
            printf("%d ", num[i]);
        }
    }

    printf("%d\n%d\n", maior, menor);

    return 0;
}