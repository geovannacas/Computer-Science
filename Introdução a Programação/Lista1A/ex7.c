#include <stdio.h>

int main() {
    int n, b, p;
    scanf("%d", &n);
    p = 128;

    if(n <= 0 || n >= 255) {
        printf("Numero invalido!\n");

    } else{
        
        while(p > 0){
            b = n/p;
            printf("%d", b);
            n=n%p;
            p=p/2;
        }
        printf("\n");
    }

    return 0;
}