#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,t[65],fac;
bool cmp(int a,int b){
    return a > b;
}
bool vis[65];

bool dfs(int st,int sum,int x,int now){
    if(now == fac) return dfs(1,sum,x,0);
    if(x > n) return sum == 0 && now == 0;
    if(now + sum < fac) return 0;
    if(now == 0)  {if(sum %fac != 0) return 0;}
    else  {if((sum - fac + now) % fac != 0) return 0;}
    for(int i = st; i<= n;i++){
        if(now + t[i] > fac) continue;
        if(!vis[i]){
            vis[i] = 1;
            if(dfs(i + 1,sum - t[i],x + 1,now + t[i])) return 1;
            vis[i] = 0;
            while(t[i] == t[i + 1]) i++;
            if(now + t[i] == fac || now == 0 ) return 0;
        }
    }
    return 0;
}

int main()
{
    while(scanf("%d",&n) == 1 && n){
        int sum = 0;
        for(int i = 1;i <= n;i++) {scanf("%d",&t[i]);sum += t[i];}
        sort(t + 1 ,t + n +1 ,cmp);
        for(fac = t[1];fac <= sum ;fac++){
            if(sum%fac == 0){
//                printf("------------\n");
                memset(vis,0,sizeof(vis));
                if(dfs(1,sum,1,0)){
                    printf("%d\n",fac);break;
                }
            }
        }
    }
    return 0;
}
