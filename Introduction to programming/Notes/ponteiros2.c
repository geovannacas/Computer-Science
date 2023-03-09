#include <stdio.h>

int main()
{   
    int x;
    int *pi;
    scanf("%d", &x); // lê x

    pi = &x;
    scanf("%d", pi); // lê x
    
    return 0;
}