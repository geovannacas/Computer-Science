#include <stdio.h>

int distancia(float ax, float ay, float bx, float by){
    float x, y;
    if(ax > bx || ax == bx){
        x = ax - bx;
    } else {
        x = bx - ax;
    }

    if(ay > by || ay == by){
        y = ay - by;
    } else{
        y = by - ay;
    }

    printf("A distância dos pontos é (%.1f, %.1f)\n", x, y);
}

int main(){
    float ax, ay, bx, by;

    printf("Digite x1 e y1:\n");
    scanf("%f %f", &ax, &ay);
    printf("Digite x2 e y2:\n");
    scanf("%f %f", &bx, &by);

    distancia(ax, ay, bx, by);

    return 0;
}