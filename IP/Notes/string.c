#include <stdio.h>

int main(){
	char s[5] = "1234";
	s[2] = 'X';
	*(s+3) = '?';
	printf("%s\n", s);
	return 0;
}