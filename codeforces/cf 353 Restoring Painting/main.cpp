#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    long long  n,a,b,c,d;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d);
    long long e = b - c;
    if(e < 0) e = 0 - e;
    long long  f = a - d;
    if(f < 0) f = 0 - f;
    if(n - e - f > 0)printf("%I64d\n",n*(n - e - f));
    else printf("0\n");
    return 0;
}
