#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
const int INF = 45000;
typedef pair<int,int> P;
queue<P> que;
vector<P> vt;
char s[203][203];
int n,sx,sy,ex,ey,d[203][203],vis[203][203];
int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
int bfs(){
    while(!que.empty()) que.pop();
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            d[i][j] = INF;
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    while(!que.empty()){
        P p = que.front();que.pop();
        if(p.first == gx && p.second == gy) break;
        if(s[nx][ny] != '*'){
            for(int i = 0;i < 4;i++){
                int nx = p.first + dx[i],ny = p.second + dy[i];
                if(0 <= nx && nx < n && ny < n && ny >= 0 && s[nx][ny] != '#' && d[nx][ny] == INF && s[nx][ny] != '*'){
                    que.push(P(nx,ny));
                    d[nx][ny] == d[p.first][p.second] + 1;
                }
            }
        }
        if(s[nx][ny] == '*') {
            int l = vt.size();
            for(int i = 0;i < l;i++){
                if(v[i].first != nx && v[i].second != ny){

                }
            }
        }
    }
    return d[gx][gy];
}
int main()
{
    int T;scanf("%d",&T);
    for(int k = 1;k <= T;k++){
        scanf("%d",&n);
        for(int i = 0;i < n;i++) scanf("%s",s[i]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++){
                if(s[i][j] == 'P') sx = i,sy = j;
                else if(s[i][j] == 'D') ex = i,ey = j;
                else if(s[i][j] == '*') vector.push_back(P(i,j));
            }
        vt.clear();
        ini(vis,0);ini(d,0);
        int ans = bfs();
        printf("Case %d: ",k);
        if(ans == INF) printf("impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}
