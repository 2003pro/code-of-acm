#include <bits/stdc++.h>
const int N = 100000;
using namespace std;
int a[N+3],b[N+3],vis[N+3];
int main()
{
    int n,k,sum = 0,ans = 0;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++){scanf("%d",&a[i]);sum += a[i];}
    for(int i = 0;i < k;i++){
        scanf("%d",&b[i]);
        vis[b[i]] = 1;
        ans += a[b[i]]*(sum - a[b[i]]);
    }
    if(vis[n] == 0 && vis[1] == 0) ans += a[n]*a[1];
    for(int i = 1;i < n;i++){
        if(vis[i] == 0&&vis[i+1] == 0) ans += a[i]*a[i+1];
    }
    for(int i = 0;i < k-1;i++){
        for(int j = i+1;j < k;j++){
            ans -= a[b[i]]*a[b[j]];
        }
    }
    printf("%d\n",ans);
}
