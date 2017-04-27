#include <bits/stdc++.h>
#define in freopen("perechi3.in","r",stdin)
#define out freopen("perechi3.out","w",stdout)
#define rep(i,j,k) for(ll i = (ll)j;i <= (ll)k;i++)
using namespace std;
typedef long long ll;
int main()
{
    in;out;
    int T;ll n;scanf("%d",&T);
    while(T--){
        scanf("%I64d",&n);
        ll sum = 0;
        double l = sqrt(1.0*n);
        rep(i,1,l) sum += n/i - (i-1) - (i*i <= n?1:0);
        sum *= 2;
        sum += (ll)l;
        printf("%I64d\n",sum);
    }
    return 0;
}
