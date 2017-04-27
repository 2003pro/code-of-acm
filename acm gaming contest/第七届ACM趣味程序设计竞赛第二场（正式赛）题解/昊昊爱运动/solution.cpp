#include<cstdio>
#include<queue>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<ctype.h>
#include<set>
#include<vector>
#include<map>
#include<time.h>
#include<list>
#include<stack>
using namespace std;
#define mod 1000000007
typedef long long LL;
const double PI=acos(-1.0);
const double  eps=1e-9;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
int a[2005];
bool f[101];
int ans[2002][2002];
int main(){
    int x,n,i,j,m;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++){
        memset(f,0,sizeof(f) );
        x=0;
        for (j=i;j<n;j++){
            if ( f[a[j] ]==0 ) { f[a[j] ]=1; x++;}
            ans[i][j]=x;
        }
    }
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++){
        scanf("%d%d",&x,&j);
        printf("%d\n",ans[x-1][j-1]);
    }
    return 0;
}
