#include <bits/stdc++.h>

using namespace std;
int a[103],b[103];
int main()
{
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&l,&r);
        int ans = 0;
        for(int j = l;j <= r;j++) ans += a[j];
        b[i] = ans;
    }
    int ans = 0;
    for(int i = 0;i < m;i++) ans += (b[i] > 0?b[i]:0);
    printf("%d\n",ans);
    return 0;
}
