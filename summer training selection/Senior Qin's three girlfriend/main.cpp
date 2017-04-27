#include <iostream>
#include <cstdio>
#include <cstring>


const int N = 100009;
char b[N];
int next[N],vis[N];

void makeNext(){
    memset(next,0,sizeof(next));
    next[0] = 0;
    int l = strlen(b);
    for(int i = 0,j = 1;j < l;++j){
        while(i > 0&&b[i] != b[j]) i = next[i - 1];
        if(b[i] == b[j]) i++;
        next[j] = i;
    }
}

int solve(){
    memset(vis,0,sizeof(vis));
    int n = strlen(b);
    int ans = 0,tmp = n;
    while(tmp > 0){
        if(n >= tmp * 2) vis[tmp] = 1;
        tmp = next[tmp];
    }
    for(int i = 0; i < n;i++){
        tmp = i;
        while(tmp > 0){
            if(vis[tmp]&&i >= tmp * 2&&n >= i + tmp){
                ans = std::max(ans,tmp);break;
            }
            tmp = next[tmp];
        }
    }
    return ans;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",&b);
        makeNext();
        int s = solve();
        printf("%d\n",s);
    }
    return 0;
}
