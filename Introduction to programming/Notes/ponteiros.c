#include <stdio.h>

int main()
{
		int x = 2;
		int *pi;
		pi = &x;
		*pi = 10;

		printf("%d\n", x);
		
		printf("%p: x\n", &x);
		
		printf("%p: pi\n", pi);

		printf("%d: *pi\n", *pi);

		return 0;
}