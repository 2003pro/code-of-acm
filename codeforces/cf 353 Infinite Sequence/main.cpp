#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    long long a,b,c;
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    long long d = b - a;
    if(c == 0 &&d == 0) printf("YES\n");
    else if(c == 0 && d != 0) printf("NO\n");
    else if(d%c == 0 && d/c >= 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
