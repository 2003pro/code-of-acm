#include <bits/stdc++.h>

using namespace std;
#define in freopen("meciul.in","r",stdin)
#define out freopen("meciul.out","w",stdout)
#define rep(i,j,k) for(int i = (int)j;i < (int)k;i++)
#define ini(x,y) memset(x,y,sizeof(x))
const int N = 100003;
int fa[2*N];
int findfa(int x){return fa[x] == x?x:fa[x] = findfa(fa[x]);}
int comb(int x,int y){int fx = findfa(x),fy = findfa(y);if(fx != fy)fa[fx] = fy;}
int main()
{
    in;out;
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&n,&m);
        rep(i,1,2*n+1) fa[i] = i;
        rep(i,0,m) {
            scanf("%d%d",&a,&b);
            if(findfa(a) == findfa(b)) {printf("NO\n");}
            else {
                printf("YES\n");
                comb(a,b+n);comb(b,a+n);
            }
        }
    }
    return 0;
}
