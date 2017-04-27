#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
char s[100003];
int mp[100003];
int vis[4];
int main()
{
    scanf("%s",s);
    int l = strlen(s),ans = 0;
    if(l%4 == 1 || l%4 == 3) printf("-1\n");
    else {
        for(int i = 0;i < l;i++){
            if(s[i] == 'U') vis[0]++;
            else if(s[i] == 'D') vis[1]++;
            else if(s[i] == 'R') vis[2]++;
            else if(s[i] == 'L') vis[3]++;
        }
        int a = std::max(abs(vis[0] - vis[1]),abs(vis[2] - vis[3])), b = std::min(abs(vis[2] - vis[3]),abs(vis[0] - vis[1]));
        ans = b + (a-b)/2;
        printf("%d\n",ans);
    }
    return 0;
}
