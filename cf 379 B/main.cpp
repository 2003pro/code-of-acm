#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll k[7];
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&k[2],&k[3],&k[5],&k[6]);
    ll a = min(k[2],min(k[5],k[6]));
    k[2] -= a;k[5] -= a;k[6] -= a;
    ll b = min(k[2],k[3]);
    ll ans = a*256 + b*32;
    printf("%I64d\n",ans);
    return 0;
}
