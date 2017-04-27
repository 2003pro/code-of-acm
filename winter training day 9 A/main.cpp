#include <bits/stdc++.h>
#define in freopen("anniversary.in","r",stdin)
#define out freopen("anniversary.out","w",stdout)
using namespace std;
const double EPS = 1e-10;

int main()
{
    in;out;
    int w,h,ans;int x,y,x1,y1;
    scanf("%d%d",&w,&h);
    scanf("%d%d",&x,&y);
    scanf("%d%d",&x1,&y1);
    if(x != x1)
        printf("%d 0 %d %d\n",x,x1,h);
    else

        printf("0 %d %d %d\n",y,w,y1);
    return 0;
}
