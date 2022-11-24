#include <stdio.h>

int main(){

    int n1, n2, n3, valor;

    scanf("%d%d%d", &n1, &n2, &n3);

    if((n1/10 != 0) || (n2/10 != 0) || (n3/10 != 0)){
        printf("DIGITO INVALIDO\n");
    } else {
        valor = n1*100 + n2*10 + n3;
        printf("%d, %d\n", valor, valor*valor);
    }

    return 0;
}