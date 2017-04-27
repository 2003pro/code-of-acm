#include <bits/stdc++.h>

using namespace std;
char s[100005];
int vis[27],a[27],b[27];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        int l = strlen(s),t = 0,l1 = 0,nx = -1,nx1;
        for(int i = 0;i < l;i++){
            if(!vis[s[i] - 'a']) {a[t] = s[i] - 'a';b[t++] = s[i] - 'a';vis[s[i] - 'a'] = 1;l1++;}
        }
        sort(b,b+l1);
        for(int i = 0;i < l1;i++) if(a[i] != b[i]) {nx = a[i],nx1 = b[i];break;}
//        for(int i = 0;i < l1;i++) printf("%d %d\n",a[i],b[i]);
        if(nx != -1){
            for(int i = 0;i < l;i++) {
                if(s[i] - 'a' == nx) s[i] = 'a' + nx1;
                else if(s[i] - 'a' == nx1) s[i] = 'a' + nx;
            }
        }
        for(int i = 0;i < l;i++) printf("%c",s[i]);printf("\n");
    }
    return 0;
}
