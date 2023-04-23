#include <stdio.h>

int main(){
    int a, b, c, n;
    char x, y, z;
    n = 0;

    scanf("%d %d %d\n", &a, &b, &c);
    scanf("%c%c%c", &x, &y, &z);

    if(a > b){
        n = b;
        b = a;
        a = n;
    }
    if(a > c){
        n = c;
        c = a;
        a = n;
    }
    if(b > c){
        n = c;
        c = b;
        b = n;
    }

    if(x == 'A' && y == 'B' && z =='C'){
        printf("%d %d %d\n", a, b, c);
    }
    if(x == 'C' && y == 'B' && z =='A'){
        printf("%d %d %d\n", c, b, a);
    }
    if(x == 'A' && y == 'C' && z =='B'){
        printf("%d %d %d\n", a, c, b);
    }
    if(x == 'B' && y == 'C' && z =='A'){
        printf("%d %d %d\n", b, c, a);
    }
    if(x == 'C' && y == 'A' && z =='B'){
        printf("%d %d %d\n", c, a, b);
    }  
    if(x == 'B' && y == 'A' && z =='C'){
        printf("%d %d %d\n", b, a, c);
    }

    return 0;
}