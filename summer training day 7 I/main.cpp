#include <bits/stdc++.h>

using namespace std;
int a[101],b[101],n,k;
int main()
{
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    scanf("%d %d",&n,&k);
    int d = n/k;int x,ct = 0,ans = 0;
    for(int i = 0;i < n;i++) {scanf("%d",&x);a[x]++;}
    for(int i = 0;i < 101;i++) {
        if(a[i] != 0) {b[ct] = a[i];ct++;}
    }
    for(int i = 0;i < ct;i++){
        if(b[i] - d > 0) ans += b[i] - d;
    }
    printf("%d\n",ans);
    return 0;
}
