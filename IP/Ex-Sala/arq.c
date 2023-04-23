#include <stdio.h>

int main(){

    FILE * arq = NULL;
    char str[64];
    int n;
    char ch;

    arq = fopen("texto", "r");

    if(arq !=  NULL){
        printf("Sucesso!\n");
    } else{
        printf("O arquivo não existe.\n");
    }

    while(){
        if(fscanf(arq, "%s", str) == EOF) break;
        printf("%d, ", );
    }

    
    


    return 0;
}