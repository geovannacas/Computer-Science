#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    float aw, ax, ay, az;
} Pontos;

void CalculoDistancia(Pontos *pontos, int n){
    int i;
    float total;

    for(i = 0; i < n; i++){
        if(i == 0){
            total = pow((pontos[i].aw - pontos[i+1].aw), 2)+pow((pontos[i].ax - pontos[i+1].ax), 2)+pow((pontos[i].ay - pontos[i+1].ay), 2)+pow((pontos[i].az - pontos[i+1].az), 2);
            printf("%.2lf\n", sqrt(total)); 
        } else if(n > 2 && i != 1){
            total = pow((pontos[i-1].aw - pontos[i].aw), 2)+pow((pontos[i-1].ax - pontos[i].ax), 2)+pow((pontos[i-1].ay - pontos[i].ay), 2)+pow((pontos[i-1].az - pontos[i].az), 2);
            printf("%.2lf\n", sqrt(total)); 
        }
    }

}

int main(){
    int n, i;
    Pontos* pontos;
    scanf("%d", &n);

    pontos = (Pontos*) malloc(n * sizeof(Pontos));

    for(i = 0; i < n; i++){
        scanf("%f %f %f %f", &pontos[i].aw, &pontos[i].ax, &pontos[i].ay, &pontos[i].az);
    }

    CalculoDistancia(pontos, n);

    free(pontos);

    return 0;
}