#include <stdio.h>

void swap(int *A, int *B)
{
    int t;
    t = *A;
    *A = *B;
    *B = t;
}

int main()
{
    int A, B;
    A = 10;
    B = 20;

    printf("%d, %d\n", A, B);

    swap(&A, &B);

    printf("%d, %d\n", A, B);

    return 0;
}