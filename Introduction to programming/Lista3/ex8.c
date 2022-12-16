#include <stdio.h>
#include <string.h>

int main(){
    int n, i = 0, j = 0, k = 0, half, length;
    char txt[1050];
    char aux[1050];

    scanf("%d", &n);

    while (n--){
        getchar();
        scanf("%[^\n]", txt);

        length = strlen(txt);


        for(i=0; i<length;i++)
        {  
            if((txt[i] >= 65 && txt[i]<= 90)|| ( txt[i] >= 97 && txt[i]<= 122)){
                txt[i]+=3;
            }
        }

        j=0;
        
        for(k = length - 1; k >= 0; k--) {
            aux[j] = txt[k];
            j++;
        }
        
        aux[j] = '\0';
        half = length/2;

        for(i=half;i<length;i++)
        {
            aux[i] = aux[i] - 1;
        }

        printf("%s\n", aux);
        
    }

    return 0;
}