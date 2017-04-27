#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,l,r;
    int mi = n;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&l,&r);
        mi = min(mi,r-l+1);
    }
    printf("%d\n",mi);
    int a = n/mi,b = n%mi;
    for(int i = 0;i < a;i++){
        for(int j = 0;j < mi;j++)printf("%d ",j);
    }
    for(int i = 0;i < b;i++) printf("%d ",i);
    return 0;
}
