#include <stdio.h>

char V[5] = { 97, 101, 105, 111, 117};

int main(){
    int n, j, cont, v, c;
    char frase[127];

    scanf("%d", &n);

    while(n--){
        getchar();
        scanf("%[^\n]", frase);
        v = 0;
        c = 0;
        cont = 0;
        j = 0;

        while(frase[j] != '\0'){
            if(frase[j] == 97 || frase[j] == 101 || frase[j] == 105 || frase[j] == 111 || frase[j] == 117 || frase[j] == 66 || frase[j] == 69 || frase[j] == 73 || frase[j] == 79 || frase[j] == 85){
                v++;
                cont++;
            } else{
                if(frase[j] >= 65 && frase[j] <= 90 || frase[j] >= 97 && frase[j] <= 122){
                    c++;
                    cont++;
                }
            }

            j++;
        }

        printf("Letras = %d\nVogais = %d\nConsoantes = %d\n", cont, v, c);
    }

    return 0;
}