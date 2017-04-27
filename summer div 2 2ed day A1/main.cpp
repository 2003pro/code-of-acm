#include <bits/stdc++.h>

using namespace std;
int r,c,m[503][503],s[503][503],t;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(s,0,sizeof(s));
        scanf("%d%d",&r,&c);
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                scanf("%d",&m[i][j]);
        s[r][c] = 1;
        for(int i = c-1;i >= 1;i--){
            s[r][i] = max(s[r][i+1]-m[r][i],1);
        }
        for(int i = r-1;i >= 1;i--){
            s[i][c] = max(s[i+1][c] - m[i][c],1);
        }
        for(int i = r-1;i >= 1;i--){
            for(int j = c-1;j >= 1;j--){
                t = min(s[i+1][j],s[i][j+1]);
                s[i][j] = max(t- m[i][j],1);
            }
        }
        printf("%d\n",s[1][1]);
    }
    return 0;
}
