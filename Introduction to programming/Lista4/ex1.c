#include <stdio.h>

double det( double A[][2]){
    return A[0][0]*A[1][1] - A[0][1]*A[1][0];
}


int main(){
    double A[2][2];
    int l, c;

    for(l = 0; l <2; l++){
        for(c = 0; c < 2; c++){
            scanf("%lf", &A[l][c]);
        }
    }

    printf("%.2lf\n", det(A));

    return 0;
}