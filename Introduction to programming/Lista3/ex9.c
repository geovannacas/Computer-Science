#include <stdio.h>

int main(){
    int n, maxx = 0, i, j, qtd = 0, position;
    int num[10001];

    scanf("%d", &n);

    for(i = 0; i<n; i++)
    {
        scanf("%d", &num[i]);
    }

    for(j = 0; j <n; j++)
    {
        if(num[n-1] == num[j])
        {
            qtd++;
        }
    }

    for(j = 0; j<n; j++)
    {
        if(j == 0)
        {   
            maxx = num[j];
            position = j;
        } else{
            if(num[j] > maxx)
            {   
                maxx = num[j];
                position = j;
            } 
        }
    }

    printf("Nota %d, %d vezes\nNota %d, indice %d\n", num[n-1], qtd, maxx, position);

    return 0;
}