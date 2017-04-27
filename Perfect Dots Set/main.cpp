#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) {
            if(j == i) printf("%.10f",sqrt(2)/2);
            else printf("0");
            if(j != n - 1) printf(" ");
            else printf("\n");
        }
    }
    double m = 2*n;
    double l = (sqrt(2) + sqrt(2 + 2*n))/m;
    for(int i = 0;i < n;i++) {
        printf("%.10f",l);
        if(i != n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
