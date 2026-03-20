#include <stdio.h>

int match(unsigned long x, unsigned short y)
{
    unsigned short mask = 0xFFFF;

    while ()
    {
        /* code */
    }
    

}



int main()

{

  unsigned long x;

  unsigned short y;



  x = 28736452;

  y = 21;

  printf("X: 0x%.16lX\n", x);

  printf("Y: 0x%.4X\n", y);



  if (match(x, y))

    printf("Y está contido em X\n");

  else

    printf("Y não está contido em X\n");



  x = 28736452;

  y = 438;

  printf("X: 0x%.16lX\n", x);

  printf("Y: 0x%.4X\n", y);



  if (match(x, y))

    printf("Y está contido em X\n");

  else

    printf("Y não está contido em X\n");



  return 0;

}