#include <bits/stdc++.h>

using namespace std;
char s[4][4];
int vis[10];
int main()
{
    memset(vis,0,sizeof(vis));
    bool flag = true;
    for(int i = 1;i <= 3;i++)scanf("%s",s[i]+1);
    if(s[1][1] != s[3][3]) flag = false;
    if(s[1][2] != s[3][2]) flag = false;
    if(s[1][3] != s[3][1]) flag = false;
    if(s[2][1] != s[2][3]) flag = false;
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
