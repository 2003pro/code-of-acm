#include <bits/stdc++.h>
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
ll solve(ll n){
    return ((n-1)*(n-2)/2 + (n-1)/2*3 + (!(n%3))*5)/6;
}
int bfind(ll v){
    ll low = 3,high = 2000000000;
    while(low < high){
        ll  mid = (low + high)/2;
        if(solve(mid) >= v) high = mid;
        else if(solve(mid) < v) low = mid + 1;
    }
    return low;
}
int main()
{
    ll lb,ub;
//    int T;
//    scanf("%d",&T);
//    while(T--){
    scanf("%I64d%I64d",&lb,&ub);
    ll lb1 = bfind(lb),ub1 = bfind(ub+1);
    printf("%I64d\n",ub1 - lb1);
//    }
    return 0;
}
