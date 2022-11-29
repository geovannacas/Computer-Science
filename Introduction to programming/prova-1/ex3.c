#include <stdio.h>

int main(){
    double x, y;
    int out=0, in=0, qtd=0, q1=0, q2=0, q3=0, q4=0;

    scanf("%lf %lf", &x, &y);

    while(x!= 0 || y!=0){
        if(x < 0.5 && y < 0.5 && x > 0 && y > 0){
            q1++;
        } else if (x > 0.5 && y < 0.5 && x < 1 && y > 0){
            q2++;
        } else if(x < 0.5 && y > 0.5 && x > 0 && y < 1){
            q3++;
        } else if(x > 0.5 && y > 0.5 && y < 1 && x < 1){
            q4++;
        }

        if(x < 0 || y < 0 || x > 1 || y > 1){
            out++;
        }
        if(x == 0 || y == 0 || x == 1 || y == 1){
            in++;
        }

        qtd++;
        scanf("%lf %lf", &x, &y);
    }

    printf("Quantidade de gotas: %d\nGotas fora do experimento: %d\nGotas na borda: %d\nq1(%d), q2(%d), q3(%d), q4(%d)\n", qtd, out, in, q1, q2, q3, q4);

    return 0;
}