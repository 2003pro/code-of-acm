#include <bits/stdc++.h>

using namespace std;
char s[11][11];
int w,h,sx,sy,sdir,vis[11][11],ans = 0,ans1 = 0;
int dx[] = {0,1,0,-1,0,1,0,-1},dy[] = {-1,0,1,0,-1,0,1,0};
void dfs(int x,int y,int d){
    if(vis[x][y]) {ans1 = max(ans,ans1);return ;}
    vis[x][y] = 1;
    int nx = x + dx[d],ny = y + dy[d],dir = d;
    dir = dir % 8;
    if(nx >= 0 && nx < w && ny >= 0 && ny < h && s[nx][ny] != '*') {ans++;dfs(nx,ny,dir);ans--;}
    else{
        for(int i = dir + 1;i < dir + 4;i++){
            nx = x + dx[i],ny = y + dy[i];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h && s[nx][ny] != '*'){
                ans++;
                dfs(nx,ny,i);
                ans--;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&w,&h);
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < w;i++)scanf("%s",s[i]);
    for(int i = 0;i < w;i++)
        for(int j = 0;j < h;j++){
            if(s[i][j] == 'U' ) sx = i,sy = j,sdir = 0;
            else if(s[i][j] == 'R' ) sx = i,sy = j,sdir = 1;
            else if(s[i][j] == 'D' ) sx = i,sy = j,sdir = 2;
            else if(s[i][j] == 'L' ) sx = i,sy = j,sdir = 3;
        }
    s[sx][sy] = '.';ans = 0;
    dfs(sx,sy,sdir);
    printf("%d\n",ans1);
    return 0;
}
