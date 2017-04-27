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
const int mod = 1000000009;
map<int,int> mp;
int n,m,b[103],a[103];
int finds(int x){
    if(a[x]!=x) return finds(a[x]);
    else return x;
}

void unions(int x,int y){
    int ax = finds(x);
    int ay = finds(y);
    a[ay] = ax;
}

ll cala(int x){
    ll n = (ll)x,ans = 1;
    while(n >= 1){
        ans = (ans*(n--))%mod;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);bool flag = false;
    if(n == 2) {printf("1\n");return 0;}
    for(int i = 1;i <= m;i++) scanf("%d",&b[i]);
    for(int i = 1;i <= n;i++) a[i] = i;
    for(int i = 1;i <= m;i++){
        int fx = finds(i);int fy = finds(b[i]);
        unions(i,b[i]);
        if(fx == fy) flag = true;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        int f = finds(i);
        if(mp[f]++ == 0) cnt++;
    }
    if(flag) {printf("0\n");return 0;}
    ll ans = 2*cala(cnt);
    printf("%I64d\n",ans);
    return 0;
}
