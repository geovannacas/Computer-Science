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



float float2(float value)
{
    U u;
    u.f = value;

    unsigned int sign = getsig(u.i);
    unsigned int exp  = getexp(u.i);
    unsigned int frac = getfrac(u.i);

    printf("Valor antes: %f\n", u.f);

    exp += 1;

    u.i = makefloat(sign, exp, frac);
    printf("Valor após:  %f\n", u.f);

    return u.f;
}

void main()
{
    float value = 0.125;

    float2(value);

    float value2 = 0.625;

    float2(value2);

    float value3 = 0.5;

    float2(value3);
}