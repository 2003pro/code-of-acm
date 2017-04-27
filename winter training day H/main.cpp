#include <bits/stdc++.h>

using namespace std;
int mp[11][11][11],ma,tt;
void dfs(int x,int y,int z){
    if(x < 1 || x > 10 || y < 1 || y > 10 || z < 1 || z > 10) {
        ma = max(ma,tt);printf("---\n");return ;
    }
    else {
        tt += mp[x][y][z];int m = tt;
        dfs(x,y+1,z);
        tt = m;
        dfs(x,y,z+1);
        tt = m;
        dfs(x-1,y,z);
        tt = m;
    }
}
int main()
{
    int T,n,x,y,z,c;scanf("%d",&T);
    while(T--){
        memset(mp,0,sizeof(mp));
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d%d%d%d",&x,&y,&z,&c);
            mp[x][y][z] += c;
        }
        ma = tt = 0;
        dfs(10,1,1);
        printf("%d\n",ma);
    }
    return 0;
}
