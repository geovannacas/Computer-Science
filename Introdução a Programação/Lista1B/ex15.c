#include <stdio.h>

int main(){
    int n, A, SdA = 0, SdB = 0, K, i = 0;

    scanf("%d", &n);

    A = 1;
    while (1)
    {
        SdA = 0;
        for(K = 1; K <= A/2; K++){
            if (A % K == 0)
            {
                SdA += K;
            }
            
        }

        if(SdA > A){
            SdB = 0;
            for(K = 1; K <= SdA/2; K++){
                if (SdA % K == 0)
                {
                    SdB += K;
                }
            
            }
            
            if(SdB == A){
                i++;
                printf("(%d,%d)\n", A, SdA);

                if(i == n) {
                    break;
                }
            }
        }

        A++;

    }
    
    return 0;
}