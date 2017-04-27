#include <bits/stdc++.h>
#define in freopen("in.txt","r",stdin)
typedef long long ll;
using namespace std;
ll mp[103],sl[103];
ll solve(ll s,ll k){
    ll cur = s,cnt = 0,cnt1 = 0;
    ll a[103],b[103];
    mp[cur] = 1;a[0] = cur;
    while(mp[cur] < 2){
        sl[cur] = cnt;
        cur *=2;
        if(cur >= 100) {cur %=100;cnt1++;}
        mp[cur]++;cnt++;a[cnt] = cur + cnt1*100;
    }
    ll rep0 = cnt1*100,rep1 = a[cnt] - a[sl[cur]],rept = cnt - sl[cur];
    if(k < cnt) return a[k];
    else{
        ll tt = (k/rept - 1)*rept + a[k%rept + rept];
        return tt;
    }
}
int main()
{
//    in;
    ll T,n,k;scanf("%I64d",&T);
    while(T--){
        scanf("%I64d %I64d",&n,&k);
        ll l = n%100,sum = n - n%100;
        memset(mp,0,sizeof(mp));
        memset(sl,0,sizeof(sl));
        sum += solve(l,k);
        printf("%I64d\n",sum);
    }
    return 0;
}
