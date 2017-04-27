#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ini(x,y) memset(x,y,sizeof(x));
typedef long long ll;
using namespace std;
ll s[20003];
int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)scanf("%lld",&s[i]);
    ll ans = 0;
    while(n > 1){
        int mi1 = 0,mi2 = 1;
        if(s[mi1] > s[mi2])swap(mi1,mi2);
        for(int i = 2;i < n;i++){
            if(s[mi1] > s[i]){mi2 = mi1,mi1 = i;}
            else if(s[mi2] > s[i]) mi2 = i;
        }
        int t = s[mi1] + s[mi2];ans += t;
        if(mi1 == n-1) swap(mi1,mi2);
        s[mi1] = t;
        s[mi2] = s[n-1];
        n--;
    }
    printf("%lld\n",ans);
    return 0;
}
