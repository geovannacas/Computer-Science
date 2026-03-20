#include <stdio.h>

struct S {

  char  c[3]; // 0

  int   a; // 4

  union {

    char x[9]; // 9

    long y; // 8
    // 12
  } d; // 8

  short b; // 24

};


void offsets(struct S *ptr) {
    size_t offset_a = (size_t)(&ptr->a) - (size_t)ptr;
    size_t offset_b = (size_t)(&ptr->b) - (size_t)ptr;
    size_t offset_c = (size_t)(&ptr->c) - (size_t)ptr;
    size_t offset_d = (size_t)(&ptr->d) - (size_t)ptr;
    
    printf("Offset de 'a': %zu\n", offset_a);
    printf("Offset de 'b': %zu\n", offset_b);
    printf("Offset de 'c': %zu\n", offset_c);
    printf("Offset de 'd': %zu\n", offset_d);
}



//----------------------------------------------

// Cria a variável varS

struct S varS;



int main() {

  offsets(&varS);

  return 0;

}