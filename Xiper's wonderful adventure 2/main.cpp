#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct p{
    int x,y,z;
};
const int  N = 51;
const int INF = 999999;
int n,l,r;
int sx,sy,sz;
int gx,gy,gz;
char m[N][N][N];
int d[N][N][N];
int dx[6] = {1,-1,0,0,0,0},dy[6] = {0,0,1,-1,0,0},dz[6] = {0,0,0,0,1,-1};
bool canMove(int x,int y,int z){
    return x >= 0&&x < l&&y >= 0&&y < r&&z >= 0&&z < n&&m[x][y][z] != 'x'&&d[x][y][z] == INF;
}

int bfs(){
    queue<p> gg;
    struct p t1;
    for(int i = 0;i <n;i++){
        for(int j = 0;j < l;j++){
            for(int k = 0;k < r;k++){
                d[j][k][i] = INF;
            }
        }
    }
    t1.x = sx;t1.y = sy;t1.z = sz;
    gg.push(t1);
    d[sx][sy][sz] = 0;
    while(!gg.empty()){
        p t = gg.front();
        gg.pop();
        if(t.x == gx&&t.y == gy&&t.z == gz) break;
        if(m[t.x][t.y][t.z] == 'U') {
            for(int i = 0;i < 5;i++){
                int nx = t.x + dx[i];
                int ny = t.y + dy[i];
                int nz = t.z + dz[i];
                if(canMove(nx,ny,nz)) {
                    struct p t2;
                    t2.x = nx;t2.y = ny; t2.z = nz;
                    gg.push(t2);
                    d[nx][ny][nz] = d[t.x][t.y][t.z] + 1;
                }
            }
        }
        else if(m[t.x][t.y][t.z] == 'D') {
            for(int i = 0;i < 4;i++){
                int nx = t.x + dx[i];
                int ny = t.y + dy[i];
                int nz = t.z + dz[i];
                if(canMove(nx,ny,nz)) {
                    struct p t2;
                    t2.x = nx;t2.y = ny; t2.z = nz;
                    gg.push(t2);
                    d[nx][ny][nz] = d[t.x][t.y][t.z] + 1;
                }
            }
            int nx = t.x + dx[5];
            int ny = t.y + dy[5];
            int nz = t.z + dz[5];
            if(canMove(nx,ny,nz)) {
                struct p t2;
                t2.x = nx;t2.y = ny; t2.z = nz;
                gg.push(t2);
                d[nx][ny][nz] = d[t.x][t.y][t.z] + 1;
            }
        }
        else {
            for(int i = 0;i < 4;i++){
                int nx = t.x + dx[i];
                int ny = t.y + dy[i];
                int nz = t.z + dz[i];
                if(canMove(nx,ny,nz)) {
                    struct p t2;
                    t2.x = nx;t2.y = ny; t2.z = nz;
                    gg.push(t2);
                    d[nx][ny][nz] = d[t.x][t.y][t.z] + 1;
                }
            }
        }
    }
    if(d[gx][gy][gz] == INF ) return -1;
    else return d[gx][gy][gz];
}

int main()
{
    char str;
    scanf("%d%d%d",&n,&l,&r);
    for(int i = 0;i <n;i++){
        for(int j = 0;j < l;j++){
            for(int k = 0;k < r;k++){
                cin>>str;
                m[j][k][i] = str;
                if(str == 'X' ) {sx = j;sy = k;sz = i;}
                else if(str == 'Y')    {gx = j;gy = k;gz = i;}
            }
        }
    }
    printf("%d\n",bfs());
    return 0;
}
