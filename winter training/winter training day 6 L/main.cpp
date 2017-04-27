#include <bits/stdc++.h>
#define in freopen("semipal.in","r",stdin)
#define out freopen("semipal.out","w",stdout)
using namespace std;
typedef long long ll;
ll cals(ll n){
    ll ans = 1,a = 2;
    while(n) {
        if(n % 2 == 1)
        ans *= a;
        n /= 2;
        a *= a;
    }
    return ans;
}
int main()
{
    in;out;
    int n;ll t,k;scanf("%d",&n);
    while(n--){
        scanf("%I64d%I64d",&t,&k);
        ll l = cals(t-2),ans,cnt = t - 2;
        string s;
        if(k <= l) {
            k--;
            while(cnt--){
                if(k & 1) s += 'b';
                else s += 'a';
                k >>= 1;
            }
            reverse(s.begin(),s.end());
            cout<<'a'<<s<<'a'<<endl;
        }
        else {
            k = k - l - 1;
            while(cnt--){
                if(k & 1) s += 'b';
                else s += 'a';
                k >>= 1;
            }
//            cout<<s<<endl;
            reverse(s.begin(),s.end());
            cout<<'b'<<s<<'b'<<endl;
        }
    }
    return 0;
}
