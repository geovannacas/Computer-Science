#include <stdio.h>

long int string2int(const char * str)
{
    long int n = 0;
    int s = 1;

    while(*str != '\0' && *str == '+' || *str == '-')
    {
        if(*str == '-') s*= -1;
        str++;
    }

    while (*str != '\0' && *str >= '0' && *str <= '9')
    {
        n = n*10 + (*str - '0');
        str++;
    }
    
    return n*s;
}


int main()
{
    char str[128];
    long int n;

    scanf("%s", str);
    n = string2int(str);
    printf("%ld %ld\n", n, n*2);

    while ( scanf("%s", str) != EOF)
    {
        n = string2int(str);
        printf("%ld %ld\n", n, n*2);
        scanf("%s", str);
    }

    return 0;
}