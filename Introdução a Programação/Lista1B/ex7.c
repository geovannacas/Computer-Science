#include <stdio.h>

int main(){ 
    int n;
    int x = 0, y = 0;
    double mediapar = 0, mediaimpar = 0;

    while (1){
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        if(n % 2 == 0 && n != 0){
            mediapar += n;
            x++;
        } else{
            mediaimpar += n;
            y++;
        }
    }

    if(x != 0){
        mediapar = mediapar/x;
    }
    if(y != 0){
        mediaimpar = mediaimpar/y;
    }


    printf("MEDIA PAR: %lf\n", mediapar);
    printf("MEDIA IMPAR: %lf\n", mediaimpar);

    return 0;
}