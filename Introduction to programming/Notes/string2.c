#include <stdio.h>

int main(){
		int i;
		char s[5] = { 1,2,3,4,5};
		s[2] = 'a';
		*(s+3) = ' ';
				
		for(i=0; i<5; i++){
				printf("%d\n", s[i]); // OU: printf("%d, ", *(s+i));
		}
		return 0;
}