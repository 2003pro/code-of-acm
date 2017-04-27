#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q,a[10003],x,y = 0;
    while(scanf("%d%d",&n,&q)!=EOF){
        y++;
        printf("CASE# %d\n",y);
        for(int i = 0;i < n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        while(q--){
            scanf("%d",&x);
            int l = lower_bound(a,a+n,x) - a;
            if(a[l] == x) printf("%d found at %d\n",x,l+1);
            else printf("%d not found\n",x);
        }
    }
    return 0;
}
