#include <stdio.h>

int converteEmNotasMoedas(int total);

int main(){
    int total;
    scanf("%d", &total);
    converteEmNotasMoedas(total);
    return 0;
}

int converteEmNotasMoedas(int total){
    int cem, cinquenta, dez, um, c, d, u;
    
    cem = total/100;
    c = total%100;

    cinquenta = c/50;
    d = c%50;

    dez = d/10;
    u = d%10;

    um = u/1; 

    printf("NOTAS DE 100 = %d\n", cem);
    printf("NOTAS DE 50 = %d\n", cinquenta);
    printf("NOTAS DE 10 = %d\n", dez);
    printf("MOEDAS DE 1 = %d\n", um);
}
