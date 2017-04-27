#include <bits/stdc++.h>

using namespace std;
#define in freopen("azerah.in","r",stdin)
#define out freopen("azerah.out","w",stdout)
#define rep(i,j,k) for(int i = (int)j;i < (int)k;i++)
typedef long long ll;
const ll mod = 1e9 + 7;
ll cals(ll n){
    ll ans = 1,a = 2;
    while(n) {
        if(n % 2 == 1)
        ans = (ans*a) % mod;
        n /= 2;
        a = (a*a) % mod;
    }
    return ans;
}

int main()
{
    in;out;
    int T,n;ll t,sume,sumo,ans;scanf("%d",&T);
    while(T--){
        sume = 0,sumo = 0;
        scanf("%d",&n);
        rep(i,0,n) {scanf("%I64d",&t);if(t&1) sumo++;else sume++;}
        ans = (cals(sume) - 1)%mod;
        ans = (ans + (cals(sumo-1)-1)*cals(sume))%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
