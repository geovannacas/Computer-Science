#include <stdio.h>

int soma_vet( int * v, int n)
{
		int i;
		int soma = 0;
		for(i = 0; i<n; i++)
		{
				soma += v[i];
		}
		return soma;
}

void print_vet( int * v, int n)
{
		int i;
		printf("[");
		for(i = 0; i<n; i++)
		{
				if(i!=0) printf(",");
				printf("%d", *(v+1));
		}
		printf("]\n");
}

#define NV 6

int main(){
		int i, soma;
		int s[NV] = { 70, 10, 2, 3,4, 5};
		soma = soma_vet(s, NV);
		print_vet(s, NV);
		printf("Soma: %d\n", soma);
}