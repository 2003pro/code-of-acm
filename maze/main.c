#include <stdio.h>
#include <stdlib.h>

int main()
{
    int map[30][30][30];
    int vis[30][30][30];
    int dx[4]={1,-1,0,0},int dy[4]={0,0,-1,1};
    bool can_move(int x,int y,int z)
    {
        return x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<l&&vis[x][y][z]==0;
    }
    int ans=99999999;
    void search(int x,int y,int z,int step)
    {
        if(x==endx&&y==endy&&z==endz)
        {
            if(ans>step)
               ans=step;
            return ;
        }
        vis[x][y][z]=1;
        for(i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];
            if(can_move(nx,ny,nz))
            {
                search(nx,ny,nz,step+1);
            }
            vis[x][y][z]=0;
        }
    }
    bool anwser=false;
    void dfs(int j,int sum)
    {
        if(j==n)
        {
            if(sum==k)
                answer=1;
            return ;
        }
        dfs(j+1,sum+a[i]);
        dfs(j+1,sum);
    }

}
