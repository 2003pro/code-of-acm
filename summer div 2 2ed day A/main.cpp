#include <bits/stdc++.h>
typedef long long ll;
long long m[503][503],cnt = 0;
long long ans = INT_MIN,cnt1 = INT_MAX;
long long dx[2] = {0,1},dy[2] = {1,0};
int ex,ey,r,c;
using namespace std;

void dfs(int x,int y){
    if(x == ex&&y == ey){
        if(cnt1 <= 0) ans = max(cnt1,ans);
        cnt -= m[x][y];
        cnt1 = INT_MAX;
        return ;
    }
    cnt += m[x][y];
    if(cnt <= 0)cnt1 = min(cnt,cnt1);
    for(int i = 0;i < 2;i++){
        int nx = x + dx[i],ny = y + dy[i];
        if(nx <= r&&ny <= c) {
            dfs(nx,ny);
            cnt -= m[nx][ny];
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(m,0,sizeof(m));
        scanf("%d %d",&r,&c);
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                scanf("%lld",&m[i][j]);
        ex = r,ey = c;
        dfs(1,1);
        printf("%lld\n",ans);
        if(ans >= 0)printf("1\n");
        else printf("%lld\n",abs(ans)+1);
    }
    return 0;
}
