#include <iostream>
#include <cstdio>
#include <cstring>

int p[101];

int main()
{
    int a ,T = 5 ,pre = 0,sum = 0;
    memset(p,0,sizeof(p));
    while(T--){
        scanf("%d",&a);
        if(p[a] < 3) p[a] ++;
        if(pre < a*p[a] && p[a] >= 2) pre = a*p[a];
        sum += a;
    }
    printf("%d\n",sum - pre);
    return 0;
}
