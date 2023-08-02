#include <stdio.h>
#include "tad3.h"

int main(){
    int h, l;
    printf("Digite a altura do retângulo: ");
    scanf("%d", &h);
    printf("Digite a largura do retângulo: ");
    scanf("%d", &l);

    Retangulo* r1 = criar_retangulo(l, h);

    apresentar(r1);
    printf("O perímetro de um retângulo é: %d\n", perimetro(r1));
    printf("A área do retângulo é: %d\n", area(r1));
    
    liberar(r1);

    return 0;
}
