#include <bits/stdc++.h>

using namespace std;
char s[100003];
int vis[100003];
int main()
{
    int n;scanf("%d %s",&n,s);
    for(int i = 0;i < n;i++) {
        if(s[i] == 'r') vis[i] = 1;
        else vis[i] = 0;
    }
    int flag = 1,cnt1,t1 = 0,t2 = 0,cnt2;
    for(int i = 0;i < n;i++){
        if(vis[i] != flag){
            if(vis[i] == 0) t1++;
            else if(vis[i] == 1) t2++;
        }
        flag = !flag;
    }
    cnt1 = max(t1,t2);
    flag = 0,t1 = 0,t2 = 0;
    for(int i = 0;i < n;i++){
        if(vis[i] != flag){
            if(vis[i] == 0) t1++;
            else if(vis[i] == 1) t2++;
        }
        flag = !flag;
    }
    cnt2 = max(t1,t2);
    printf("%d\n",min(cnt1,cnt2));
    return 0;
}
