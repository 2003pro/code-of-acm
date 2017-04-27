#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    int T,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        printf("%d %d %d %d\n",a,b * (b + 1)/2,b * b,b * b + b);
    }
    return 0;
}
