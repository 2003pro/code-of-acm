#include <bits/stdc++.h>

using namespace std;

int main()
{
    int xa,ya,xb,yb,xs,ys;bool flag = true;
    scanf("%d%d%d%d%d%d",&xa,&ya,&xs,&ys,&xb,&yb);
    int x1 = min(xa,xs),x2 = max(xa,xs);
    int y1 = min(ya,ys),y2 = max(ya,ys);
    if(xb < x1||xb > x2) flag = false;
    if(yb < y1||yb > y2) flag = false;
    if(flag)printf("Yes\n");
    else printf("No\n");
    return 0;
}
