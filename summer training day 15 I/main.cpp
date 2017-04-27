#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll b,c,d,k,p;
    scanf("%I64d %I64d %I64d %I64d %I64d",&b,&c,&d,&k,&p);
    ll sum = 0;
    for(ll i = 1;i <= k;i++){
        sum += c + i*d;
    }
    if(b*100 < sum*p) printf("Cash\n%.6f\n",1.0*sum*p/100 - b);
    else printf("Insurance\n%.6f\n",b - 1.0*sum*p/100);
    return 0;
}
