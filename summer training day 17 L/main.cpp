#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,b,c;
int main()
{
    scanf("%I64d %I64d %I64d",&a,&b,&c);
    if(a+b < c) {printf("Impossible\n");return 0;}
    else {
        ll a1 = max(a,b);
        a1 = min(a1,c);

        ll b1 = c - a1;
        if(a < b) printf("%I64d %I64d\n",b1,a1);
        else printf("%I64d %I64d\n",a1,b1);
    }
    return 0;
}
