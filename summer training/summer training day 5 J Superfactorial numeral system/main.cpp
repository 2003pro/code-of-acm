#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    ll p,q;
    scanf("%I64d%I64d",&q,&p);
    ll m = 1;
    while(q%p != 0){
        ll l = gcd(q,p);
        q /= l,p /= l;
        printf("%I64d ",q/p);
        q = (q%p)*(++m);p = p;
    }
    printf("%I64d\n",q/p);
    return 0;
}
