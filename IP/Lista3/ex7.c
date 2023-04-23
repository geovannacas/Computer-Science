#include <stdio.h>

int main()
{
    int i, j, n, num[10010], maxx=0, count = 0;

    scanf("%d", &n);

    while(n != 0)
    {
        maxx = 0;
        count = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &num[i]);
            if(num[i] > maxx)
            {
                maxx = num[i];
            }
        }

        for(j=0; j <= maxx; j++)
        {
            for(i = 0; i<n; i++)
            {
                if(num[i] == j)
                {
                    count++;
                }
            }

            printf("(%d) %d\n", j, count);
        }
        scanf("%d", &n);
    }
    return 0;
}