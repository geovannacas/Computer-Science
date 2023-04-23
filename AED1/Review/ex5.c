#include <stdio.h>

int main(){
    int vetor1[4], vetor2[4];

    printf("Sequência 1:\n");
    for(int i = 0; i < 4; i++){
        scanf("%d", &vetor1[i]);
    }

    printf("Sequência 2:\n");
    for(int i = 0; i < 4; i++){
        scanf("%d", &vetor2[i]);
    }

    printf("As somas em sequência são:\n");
    for(int i = 0; i < 4; i++){
        printf("%d ", vetor1[i]+vetor2[i]);
    }

    printf("\n");

    return 0;
}