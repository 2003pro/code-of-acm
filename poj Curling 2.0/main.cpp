#include <iostream>
#include <cstdio>
#include <cstring>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,sx,sy,ans;
int dx[]={0,0,1,-1},dy[] = {1,-1,0,0};
int s[23][23];
void dfs(int x,int y,int cnt){
    if(cnt >= 10 || cnt > ans) return ;
    int tt;
    for(int i = 0;i < 4;i++){
        int nx = x,ny = y; tt = 0;
        while(nx >= 0&&nx < m&&ny >= 0&&ny < n){
            nx+=dx[i],ny+=dy[i];tt++;
            if(s[nx][ny] == 3) {ans = min(cnt+1,ans);return;}
            else if(s[nx][ny] == 1){
                break;
            }
        }
        if(s[nx][ny] == 1 && tt > 1){
            s[nx][ny] = 0;dfs(nx-dx[i],ny-dy[i],cnt+1);s[nx][ny] = 1;
        }
    }
}
int main()
{
//    input;output;
    while(scanf("%d%d",&n,&m)!=EOF && n && m){
        ini(s,0);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                scanf("%d",&s[i][j]);
                if(s[i][j] == 2) sx = i,sy = j;
            }
        }
        ans = 12;
        dfs(sx,sy,0);
        printf("%d\n",(ans == 12)?-1:ans);
    }
    return 0;
}
