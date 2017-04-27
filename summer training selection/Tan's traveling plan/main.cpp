#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mn = 100003;
int mp[mn][mn],s[mn],t[mn];

int main()
{
    int a,b,c,m,n;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <=n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j) mp[i][j] = 0;
            else mp[i][j] = 1e8;
        }
    }
    for(int i = 0;i < n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        mp[a][b] = min(c,mp[a][b]);
        mp[b][a] = min(c,mp[b][a]);
    }
    for(int i = 0;i < m;i++)
        scanf("%d%d",&s[i],&t[i]);

    return 0;
}
