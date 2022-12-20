#include <stdio.h>

void print_bits(unsigned char byte) 
{
    int p = 128;
    int i,r;
    for(i = 0; i < 8; i++)
    {
        r = byte/p;
        printf("%d", r);
        byte = byte%p;
        p = p/2;
    }
}

void print_bytes(const void * p, int n)
{
    unsigned char * pc;
    int i;
    pc = (unsigned char *)p;

    for(i = 0; i < n; i++)
    {
        print_bits(*(pc+i));
        printf(" ");
    }
}

int main()
{
    unsigned int ui;
    unsigned char uc;
    unsigned short us;
    float f;
    double d;

    scanf("%lf", &d);
    uc = us = ui = f = d;   
    
    print_bytes(&uc, sizeof(unsigned char));
    printf("\n");
    print_bytes(&us, sizeof(unsigned short));
    printf("\n");
    print_bytes(&ui, sizeof(unsigned int));
    printf("\n");
    print_bytes(&f, sizeof(float));
    printf("\n");
    print_bytes(&d, sizeof(double));
    printf("\n");

    return 0;
}