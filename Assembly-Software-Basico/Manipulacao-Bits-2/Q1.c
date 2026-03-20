#include <stdio.h>

int leading_zeros(unsigned short n){
    int count = 0;
    unsigned short mask = 0x8000;

    for (int i = 0; i < 16; i++) {
        if ((n & mask) == 0) {
            count++;
        } else {
            break;
        }
        mask >>= 1;
    }

    return count;
}

int main() {

    unsigned short v, m, n, t, q;
  
    v = 0;
  
    printf("0x%04X tem número %d de 0\n", v, leading_zeros(v));

    m = 0x0083;
  
    printf("0x%04X tem número %d de 0\n", m, leading_zeros(m));
    t = 0x0607;
  
    printf("0x%04X tem número %d de 0\n", t, leading_zeros(t));
    n = 24432;
  
    printf("0x%04X tem número %d de 0\n", n, leading_zeros(n));

    q = 0xC2A4;
  
    printf("0x%04X tem número %d de 0\n", q, leading_zeros(q));
  
    return 0;
  
  }