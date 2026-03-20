#include <stdio.h>



void dump(void *p, int n) {

  unsigned char *p1 = p; // valor de p convertido em unsigned char (8bits)

  while (n--) { // cada parte do byte é impressa com valor e endereço de memoria

    printf("%p - 0x%02X\n", p1, *p1);

    p1++;

  }

}



int main() {

  short s; // (16 bits)

  int i; // (32 bits)

  long l; // (64 bits)



  s = 108;

  i = (int)s;

  printf("--- s:\n");

  dump(&s, sizeof(s));

  printf("--- i:\n");

  dump(&i, sizeof(i));



  printf("-----------------------------------------------------------------");



  i = -10;

  l = (long)i;

  printf("--- i:\n");

  dump(&i, sizeof(i));

  printf("--- c:\n");

  dump(&l, sizeof(l));



  printf("-----------------------------------------------------------------");



  l = 83728472363;

  i = (int)l;

  s = (short)l;

  printf("--- c:\n");

  dump(&l, sizeof(l));

  printf("--- i:\n");

  dump(&i, sizeof(i));

  printf("--- s:\n");

  dump(&s, sizeof(s));



  return 0;

}