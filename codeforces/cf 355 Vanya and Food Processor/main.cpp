#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

bool cmp(ll a,ll b){
    return a>b?a:b;
}


int main()
{
    ll n,h,k,t,r = 0;
    long long ans = 0;
    scanf("%I64d %I64d %I64d",&n,&h,&k);
    for(ll i = 0;i < n;i++){
        scanf("%I64d",&t);
        if(r + t < h){
            r += t;
            ans += r/k;
            r = r%k;
        }
        else {
            while(r + t > h){
                r = (r - k > 0?(r - k) : 0);
                ans++;
            }
            r += t;
            ans += r/k;
            r = r%k;
        }
    }
    if(r != 0) ans++;
    printf("%I64d\n",ans);
    return 0;
}
