#include <bits/stdc++.h>

using namespace std;
struct node{
    int w,l;
    bool operator < (const node a) const{
        return w < a.w;
    }
}s[103];
int n;
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int t;scanf("%d",&t);
        s[i].w = t;s[i].l = i;
    }
    sort(s+1,s+n+1);
    for(int i = 1;i <= n/2;i++){
        printf("%d %d\n",s[i].l,s[n-i+1].l);
    }
    return 0;
}
