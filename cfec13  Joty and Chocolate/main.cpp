#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int main()
{
    ll n,a,b,a1,b1,sum = 0;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&a1,&b1);
    printf("%I64d\n",(n/a-n/(a*b))*a1+(n/b-n/(a*b))*b1+(n/(a*b))*max(a1,b1));
    return 0;
}
