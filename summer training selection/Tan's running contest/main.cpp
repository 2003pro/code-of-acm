#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;
typedef long long ll;
int T;
ll B[103],M[103];

ll exgcd(ll a,ll b,ll &x,ll &y){
    ll d = a;
    if(b != 0){
        d = exgcd(b,a%b,y,x);
        y -= (a/b) * x;
    }
    else {
        x = 1;y = 0;
    }
    return d;
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    exgcd(a,m,x,y);
    return (m + x % m) % m;
}

ll gcd(ll a,ll b){
    return b == 0? a : gcd(b,a % b);
}
pair<ll ,ll> linearcong(){
    ll x = 0,m = 1;
    for(int i = 0;i < T;i++){
        ll a = m,b = B[i] - x,d =gcd(M[i],a);
        if(b % d != 0) return make_pair(-1,0);
        ll t = b / d * mod_inverse(a/d,M[i]/d)%(M[i]/d);
        x += m * t;
        m *= M[i] / d;
    }
    return make_pair(x%m,m);
}
int main()
{
    scanf("%d",&T);
    for(int k = 0;k < T;k++)
        scanf("%lld%lld",&M[k],&B[k]);
    pair<ll,ll> p = linearcong();
    ll m = p.first > 0 ? p.first : p.first + p.second;
    printf("%lld\n",m);
    return 0;
}
