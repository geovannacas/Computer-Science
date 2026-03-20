#include <stdio.h>

#include <math.h>



#define getsig(i)        ((i)>>31 & 1)

#define getexp(i)        ((i)>>23 & 0xff)

#define getfrac(i)       ((i) & 0x7fffff)

#define makefloat(s,e,f) ( (((s) & 1) << 31) | (((e) & 0xff) << 23) | ((f) & 0x7fffff) )



typedef union {

  float f;

  unsigned int i;

} U;



float int2float(int i)

{
    unsigned int sign = 0;
    if(i < 0)
    {
       i = -i;
       sign = 1;
    }

    if (i == 0) {
      return 0.0f;
    }

    //printf("sign: %d  ", sign);

    unsigned int E = 0;
    int mask = 1;
    for(int j = 0; j < 32; j++){
        if(i & mask)
          E = j;
        mask <<= 1;
    }
    
    unsigned int exp = E + 127;
    //printf("exp: %d", exp);

    unsigned int M = 0;

    if (E < 23) {
      M = (i << (23 - E)) & 0x7FFFFF;
    } else {
        M = (i >> (E - 23)) & 0x7FFFFF;
    }

    //printf("M: %u", M);

    U u;
    u.i = makefloat(sign, exp, M);
    return u.f;    
}



int main() {

   int i;



   printf("\n******** int2float ****************\n");



   i = 0;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 1;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = -1;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 12345;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = -12345;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 13631488;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 1879048192;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 0x7fffffff;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = -i;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   return 0;

}