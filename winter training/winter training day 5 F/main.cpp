#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (int)j;i < (int)k;i++)
using namespace std;
const int N = 1000003;
int a[3][N],b[3][N];
int main()
{
    int t,l,v1,v2,ans = 0;scanf("%d%d%d%d",&l,&t,&v1,&v2);
    int n,x,y,z;scanf("%d",&n);
    int t1 = t,t2 = t;
    rep(i,0,n){
        scanf("%d%d%d",&x,&y,&z);
        if(x == 1) t1 -= z;
        else t2 -= z;
    }
    ans = (v1*t1 + v2*t2)/l;
    printf("%d\n",ans);
    return 0;
}
