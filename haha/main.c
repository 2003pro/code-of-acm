#include <stdio.h>
#include <time.h>

int main()
{
    long long i=300000000,a[9];
    int j;
    while(i--){
            for(j = 0;j < 3;j++) a[j]++;
    }
    printf("%.2f",(double)clock()/CLOCKS_PER_SEC);
}
