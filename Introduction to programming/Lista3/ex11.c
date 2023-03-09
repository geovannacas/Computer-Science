#include <stdio.h>

int main(){
    int n, i, j, tmp;
    double  num[1000000], total;
   
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%lf", &num[i]);
    }

    for(j = 0; j < n; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(num[j] > num[i])
            {
                tmp = num[j];
                num[j] = num[i];
                num[i] = tmp;
            }
        }
    }


    if(n % 2 == 0)
    {
        total = (num[n/2]+num[(n/2)-1])/2;
        printf("%.2lf\n", total);
    } 
    else 
    {
        total = num[n/2];
        printf("%.2lf\n", total);
    }

    return 0;
}