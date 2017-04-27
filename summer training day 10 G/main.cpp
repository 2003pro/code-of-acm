#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,ct,vis[628][628],ans,ans1,xa,ya,dira,xi,yi,diri;
int dx[] = {0,-1,1,0},dy[] = {1,0,0,-1};
char di[] = {'E','N','S','W'};
void dfs(int x,int y,int d){
    int nx,ny,l,r;
    vis[x][y] = 1;
    nx = x + dx[d],ny = y + dy[d];
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
        ans++;
        dfs(nx,ny,d);
        ans--;
    }
    else{
        if(d == 0 || d == 3) l = 1,r = 2;
        else if(d == 1 || d == 2) l = 3,r = 0;
        nx = x + dx[l],ny = y + dy[l];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
            ans++;
            dfs(nx,ny,l);
            ans--;
        }
        nx = x + dx[r],ny = y + dy[r];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
            ans++;
            dfs(nx,ny,r);
            ans--;
        }
    }
    if(ans > ans1) {
        ans1 = ans;xa = xi;ya = yi;dira = diri;
    }
    vis[x][y] = 0;
}
int main()
{
    int cas = 1;
    while(scanf("%d %d",&n,&m) && (n+m)){
        ini(vis,0);ans1 = 0;
        scanf("%d",&ct);
        for(int i = 0;i < ct;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            vis[x][y] = 1;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j]){
                    for(int k = 0;k < 4;k++){
                        int xx = i + dx[k],yy = j + dy[k];
                        ans = 1;xi = i,yi = j,diri = k;
                        if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy]){
                            vis[i][j] = 1;
                            ans++;
                            dfs(xx,yy,k);
                            ans--;
                            vis[i][j] = 0;
                        }
                    }
                }
            }
        }
        printf("Case %d: %d %d %d %c\n",cas,ans1,xa,ya,di[dira]);
        cas++;
    }
    return 0;
}
