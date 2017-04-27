#include <bits/stdc++.h>
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)
using namespace std;
const int N = 103;
int vis[N][N],an[N][N];
int dx[] = {1,0,-1,0},dy[] = {0,-1,0,1};
int judge(int x,int y){
    int xx = x,yy = y;
    if(xx >= 0 && xx < 100 && yy >= 0 && yy < 100 && vis[xx][yy] == 0) return 1;
    else return 0;
}
int searchan(int x,int y){
    int xx = x,yy = y,an = 0,dir = 0;
    for(int i = 1;i < 30;i++){
        int l = i;dir = dir % 4;
        while(l--){
            xx += dx[dir],yy += dy[dir];
            if(!judge(xx,yy)) return an;
            else an++;
        }
        dir++;
        l = i;dir = dir % 4;
        while(l--){
            xx += dx[dir],yy += dy[dir];
            if(!judge(xx,yy)) return an;
            else an++;
        }
        dir++;
    }
}
int main()
{
    in;out;
    for(int i = 0;i < 100;i++)
        for(int j = 0;j < 100;j++)
            scanf("%d",&vis[i][j]);
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            if(vis[i][j] == 0){
                an[i][j] = searchan(i,j);
            }
        }
    }
    int ma = 0,maxx,mayy;
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            if(an[i][j] > ma) ma = an[i][j],maxx = i,mayy = j;
        }
    }
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            printf("%d ",an[i][j]);
        }
        printf("\n");
    }
    printf("value:%d x:%d y:%d",ma,maxx,mayy);
    return 0;
}
