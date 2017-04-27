#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;
ll n,m,mod = 9901;
ll p[10000003],a[10000003];
ll pow(ll p,ll n){
    ll ans = 1;
    while(n > 1){
        ans = (ans*p)%mod;
        n--;
    }
    return ans;
}
ll calc(ll x,ll y){
    if(n&1 == 1)

}
int main()
{
    scanf("%I64d %I64d",&n,&m);
    ll k = 2,cnt = 0;
    while(n > 1){
        if(n%k == 0){
            p[++cnt] = k%mod;
            a[cnt] = 0;
            while(n%k == 0){
                n /= k;
                a[cnt]++;
            }
        }
        else k++;
    }
    ll sum = 1;
    for(ll i = 1;i <= cnt;i++){
        sum = (sum*calc(a[i]*m,p[i]))%mod;
    }
    printf("%I64d\n",sum);
    return 0;
}
