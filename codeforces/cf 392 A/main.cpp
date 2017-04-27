#include <bits/stdc++.h>

using namespace std;
int a[103];
int main()
{
    int n,ma = 0,ans = 0;scanf("%d",&n);
    if(n == 1) {printf("0\n");return 0;}
    for(int i = 0;i < n;i++) {scanf("%d",&a[i]);ma = max(ma,a[i]);}
    for(int i = 0;i < n;i++) ans += (ma - a[i]);
    printf("%d\n",ans);
    return 0;
}
