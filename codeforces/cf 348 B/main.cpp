#include <iostream>
#include <cstdio>
#include <cstring>
#define in freopen("out.txt","r",stdin)
const int N = 100003;
int main()
{
//    in;
    int a1[N],vis[N];
    char s[N];
    memset(vis,0,sizeof(vis));
    int n,t = 1,flag = 1;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i = 1;i <= n;i++) scanf("%d",&a1[i]);
    while(t >= 1 && t <= n){
        if(vis[t]++ == 0) {
            if(s[t] == '>') t += a1[t];
            else t -= a1[t];
        }
        else {flag = 0;break;}
    }
    if(!flag) printf("OLD\n");
    else printf("NEW\n");
    return 0;
}
