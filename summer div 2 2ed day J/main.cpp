#include <bits/stdc++.h>

using namespace std;
int r,c,Time[503][503];
char s1[503][503],ans[503][503];
int dx[] = {0,0,1,-1},dy[]= {1,-1,0,0};
struct node{
    int x;
    int y;
    char s;
    int t;
};

queue <node> Q;
queue <node> q;

void bfs(struct node a,int cnt){
    int x1 = a.x,y1 = a.y;
    for(int i = 0;i < 4;i++){
        int nx = x1 + dx[i],ny = y1 + dy[i];
        if(nx < 0 || nx > r-1 || ny < 0 || ny > c-1 || ans[nx][ny] == '#'|| ans[nx][ny] == a.s || ans[nx][ny] == '*') continue;
        else if(ans[nx][ny] != a.s && islower(ans[nx][ny])) if(Time[nx][ny] == cnt + 1) ans[nx][ny] = '*';
        if(ans[nx][ny] == '.') {
            q.push((node){nx,ny,a.s,cnt+1});
            ans[nx][ny] = a.s;
            Time[nx][ny] = cnt + 1;
        }
    }
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(s1,'0',sizeof(s1));
        memset(ans,'0',sizeof(ans));
        memset(Time,0,sizeof(Time));
        scanf("%d%d",&r,&c);
        for(int i = 0;i < r;i++) scanf("%s",s1[i]);
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++){
                if(isalpha(s1[i][j])){
                    Q.push((node){i,j,s1[i][j],1});
                    Time[i][j] = 1;
                }
                ans[i][j] = s1[i][j];
            }
        int cnt = 0;
        while(!Q.empty()){
            cnt++;
            while(!Q.empty()){
                struct node t1 = Q.front();
                if(t1.t != cnt) break;
                Q.pop();
                bfs(t1,cnt);
            }
            while(!q.empty()){
                struct node t1 = q.front();
                if(ans[t1.x][t1.y] != '*') Q.push(t1);
                q.pop();
            }
        }
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                printf("%c",ans[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
