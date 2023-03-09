#include <stdio.h>

int main(){
    int M[6][6];
    int l, c;
    int soma = 0, maior = -63;

    for(l = 0; l < 6; l++){
        for(c = 0; c < 6; c++){
            scanf("%d", &M[l][c]);
        }
    }

    for(l = 1; l < 5; l++){
        for(c = 1; c < 5; c++){
            soma = (M[l-1][c-1] + M[l-1][c] + M[l-1][c+1] + M[l][c] + M[l+1][c-1] + M[l+1][c] + M[l+1][c+1]);
            if(maior <= soma){
                maior = soma;
            }
        }
    }

    printf("%d\n", maior);

    return 0;
}