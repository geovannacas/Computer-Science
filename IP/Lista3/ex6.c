#include <stdio.h>
#include <string.h>

int main(){
    int n, i = 0;
    char palavra[5];

    scanf("%d", &n);

    while(n--){
        scanf("%s", palavra);

        if(strlen(palavra) == 5){
            printf("3\n");
        } else{
            if(strchr(palavra, 'o') && strchr(palavra, 'n') || strchr(palavra, 'e') && strchr(palavra, 'n') || strchr(palavra, 'o') && strchr(palavra, 'e')){
                printf("1\n");
            } else{
                printf("2\n");
            }
        }
        
    }
    
    return 0;
}