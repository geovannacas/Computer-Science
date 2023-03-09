#include <stdio.h>
#include <string.h>

typedef struct
{
    char pais[32];
    char frase[128];
} Lista;

#define N 24

int main()
{

    int i;
    char entrada[32];

    Lista l[N] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"},
    };

    while (EOF != scanf("%s", entrada))

    {
        for (i = 0; i < N; i++)
        {
            if (strcmp(entrada, l[i].pais) == 0)
            {
                printf("%s\n", l[i].frase);
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