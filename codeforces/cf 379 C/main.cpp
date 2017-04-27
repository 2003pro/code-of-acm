#include <bits/stdc++.h>
typedef long long ll;
const int N = 200003;
ll a1[N],b1[N],c1[N],d1[N],an[N];
ll k,m,n,x,s;
using namespace std;
ll bis(ll tt){
    ll a,t = s - tt;
    while
    return c1[a];
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64",&n,&m,&k,&x,&s);
    for(ll i = 1;i <= m;i++) scanf("%I64d",&a1[i]);
    for(ll i = 1;i <= m;i++) scanf("%I64d",&b1[i]);
    for(ll i = 1;i <= k;i++) scanf("%I64d",&c1[i]);
    for(ll i = 1;i <= k;i++) scanf("%I64d",&d1[i]);
    a1[0] = x;
    for(ll i = 0;i <= m;i++) {an[i] = (n-bis(b1[i]))*a1[i];}
    sort(an,an+m+1);
    for(int i = 0;i < )
    printf("%I64d\n",an[0]);
}


