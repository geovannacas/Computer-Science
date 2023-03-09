#include <stdio.h>
#include <string.h>

struct row{
    char pais[32];
    char expr[128];
};
typedef struct row Row;

#define N 24

int main(){

    int i;
    char paisc[32];

    Row l[N] = {
{ "brasil", "Feliz Natal!"},
{ "alemanha", "Frohliche Weihnachten!"},
{ "austria", "Frohe Weihnacht!"},
{ "coreia", "Chuk Sung Tan!"},
{ "espanha", "Feliz Navidad!"},
{ "grecia", "Kala Christougena!"},
{ "estados-unidos", "Merry Christmas!"},
{ "inglaterra", "Merry Christmas!"},
{ "australia", "Merry Christmas!"},
{ "portugal", "Feliz Natal!"},
{ "suecia", "God Jul!"},
{ "turquia", "Mutlu Noeller"},
{ "argentina", "Feliz Navidad!"},
{ "chile", "Feliz Navidad!"},
{ "mexico", "Feliz Navidad!"},
{ "antardida", "Merry Christmas!"},
{ "canada", "Merry Christmas!"},
{ "irlanda", "Nollaig Shona Dhuit!"},
{ "belgica", "Zalig Kerstfeest!"},
{ "italia", "Buon Natale!"},
{ "libia", "Buon Natale!"},
{ "siria", "Milad Mubarak!"},
{ "marrocos", "Milad Mubarak!"},
{ "japao", "Merii Kurisumasu!"},
};

while (EOF != scanf("%s", paisc))
{
    for(i = 0; i<N; i++){
        if(strcmp(paisc, l[i].pais) == 0){
            printf("%s\n", l[i].expr);
            break;
        }
    }
    if (i == N)
    {
        printf("-- NOT FOUND --\n");
    }
}

    return 0;
}