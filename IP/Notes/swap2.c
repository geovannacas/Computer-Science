#include <stdio.h>

int main()
{   
    char str[10];
    int i;
    char * pc;

    scanf("%s", str);
    printf("%s\n", str);

    *str = 'Z';

    for(i = 0; i<10; i++)
    {
        if(str[i] == '\0')
        {
            printf("[NULL]");
        } else {
            printf("%c", str[i]);
        }
    }

    printf("\n");

    return 0;
}