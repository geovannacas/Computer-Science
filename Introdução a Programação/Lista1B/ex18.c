#include <stdio.h>

int main(){

    int n, f, cd, i, c = 0;

    scanf("%d", &n);

    while (n <= 1)
    {
        printf("Fatoracao nao e possivel para o numero %d!\n", n);

        scanf("%d", &n);
    }

    printf("%d =", n);

    while (n > 1)
    {
        f = 2;
        while(n % f != 0){
            while (1)
            {
                f++;
                cd = 0;

                for(i = 1; i <= f; i++){
                    if(f % i == 0) cd++;
                }
                if(cd == 2) break;
            }
        }

        n = n/f;   
        c++;

        if(c > 1) printf(" x");
        printf(" %d", f);
    }

    printf("\n");

    return 0;
}