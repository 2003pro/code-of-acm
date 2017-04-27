#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,l;
int dx[]={0,0,1,-1},dy[] = {1,-1,0,0};
char s[23][23];
void dfs(int a,int b){
    l++;
    s[a][b] = '#';
    for(int i = 0;i < 4;i++){
        int na = a +dx[i],nb = b + dy[i];
        if(na >= 0&&na <= n-1&&nb >= 0&&nb <= m-1&&s[na][nb] != '#') dfs(na,nb);
    }
    return ;
}
int main()
{
    int x,y;
    while(scanf("%d%d",&m,&n) != EOF){
        if(n == 0 && m == 0) break;
        l = 0;
        for(int i = 0;i < n;i++) scanf("%s",s[i]);
        for(int i = 0; i < n;i++)
            for(int j = 0; j < m;j++)
                if(s[i][j] == '@') x = i,y = j,s[i][j] = '.';
        dfs(x,y);
        printf("%d\n",l);
    }
    return 0;
}
