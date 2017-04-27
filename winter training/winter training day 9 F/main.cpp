#include <bits/stdc++.h>
#define in freopen("folding.in","r",stdin)
#define out freopen("folding.out","w",stdout)
using namespace std;
void fun_c(int &x, int &y)
{
        int c;
        c = y;
        y = x;
        x = c;
}
int bi(int x){
    if(x - x/2 != x/2) return x/2+1;
    else return x/2;
}
int solve(int x,int y,int x1,int y1){
    int cnt = 0;
    while(x1 < x){
        if(x1 >= bi(x)) {cnt++;break;}
        else {x = bi(x);cnt++;}
    }
    while(y1 < y){
        if(y1 >= bi(y)) {cnt++;break;}
        else {y = bi(y);cnt++;}
    }
    return cnt;
}
int main()
{
    in;out;
    int x,y,x1,y1;
    scanf("%d%d",&x,&y);
    if(x < y) fun_c(x,y);
    scanf("%d%d",&x1,&y1);
    if(x1 < y1) fun_c(x1,y1);
    if(x1 > x || y1 > y) {printf("-1\n");return 0;}
    int ans = min(solve(x,y,x1,y1),solve(x,y,y1,x1));
    printf("%d\n",ans);
    return 0;
}
