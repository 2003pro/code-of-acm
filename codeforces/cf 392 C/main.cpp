#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n,m,k,x,y,mi,ma,ser;scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&k,&x,&y);
    if(n == 1){
        mi = k/m;
        ma = mi+1;
        ll t = k%m,tt = y +(x-1)*m;
        ser = mi + (tt <= t?1:0);
    }
    else if(n == 2){
        mi = k/(2*m);
        ll t = k%(2*m);
        ma = mi + (t == 0?0:1);
        ll tt = y +(x-1)*m;
        ser = mi + (tt <= t?1:0);
    }
    else {
        mi = k / (m*(2*n-2));
        ll t = k % (m*(2*n-2));
        ll tt = y + (x-1)*m;
        if(t == 0) {ma = mi*2;ser = (x==1 || x==n)?mi:ma;}
        else if(t <= m) ma = mi*2;
        else if(t>m && t < m*n) ma = mi*2+1;
        else if(t == m*n) {ma = mi*2 +1;mi++;}
        else {
            mi++;
            ma = mi*2;
        }
        if(x == 1 || x == n){
            if(tt <= t) ser = mi + (t >= m*n?0:1);
            else ser = mi;
        }
        else {
            if(tt <= t) ser = ma;
            else ser = ma + (t >= m*n?-1:0);
        }
    }
    printf("%I64d %I64d %I64d\n",ma,mi,ser);
    return 0;
}
