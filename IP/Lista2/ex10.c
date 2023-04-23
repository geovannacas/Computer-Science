#include <stdio.h>

double compute_pi( int n );

int main(){
    int n;

    scanf("%d", &n);

    compute_pi(n);

    return 0;
}

double compute_pi( int n ){
    int i = 1;
    double total, pi = 1;

    if(n == 0){
        printf("0\n");
    } else{
        for(i = 1; i <= n; i++)
        {
            total = 1;
            if(i%2 == 1)
            {
                total = (double)(i+1)/i;
            } else{
                total = (double)i/(i+1);
            }

            pi *= total;
        }
        printf("%.12lf\n", pi*2);
    }
    

    return(total);

}