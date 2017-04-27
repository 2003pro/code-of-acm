#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<ll,ll> mp;
ll lca(ll v,ll u,ll w = -1){
    ll ans = 0;
    while(v != u){
        if(v < u) swap(v,u);
        if(mp.find(v) != mp.end()) ans += mp[v];
        if(~w)mp[v] += w;
        v >>= 1;
    }
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int fl;ll u,v;
        cin>>fl>>v>>u;
        if(fl == 1){
            ll w;cin>>w;
            lca(v,u,w);
        }
        else printf("%I64d\n",lca(v,u));
    }
    return 0;
}
