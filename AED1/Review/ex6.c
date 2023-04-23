#include <stdio.h>

int main(){
    int vetor[5], matriz[2][2], n = 0;

    printf("Digite os números do vetor:\n");
    for(int i = 0;i < 5; i++){
        scanf("%d", &vetor[i]);
    }

    printf("Digite os números da matriz:\n");
    for(int i = 0;i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &matriz[i][j]);
            for(int x = 0; x < 5; x++){
                if(vetor[x] == matriz[i][j]) n++;
            }
        }
    }

    printf("Existem %d números que existem tanto no vetor quanto na matriz.\n", n);

    return 0;
}