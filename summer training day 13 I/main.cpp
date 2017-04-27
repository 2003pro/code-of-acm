#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1000000;
ll solve(ll x){
    ll l,re,sum = 0,cur = 1;
    while(cur <= x){
        re = x/cur;l = x/re;
        sum += ((l - cur + 1)*re);
        cur = ++l ;
    }
    sum %= mod;
    return sum;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        ll x;
        scanf("%I64d",&x);
        printf("%I64d\n",solve(x));
    }
    return 0;
}

