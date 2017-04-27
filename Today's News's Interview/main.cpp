#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int N = 3003;
const int inf = 0x7fffffff;
int dis[N],vis[N],n,t;

int gcd(int a,int b){
    if(a < b) {
        int t = a;
        a = b;
        b = t;
    }
    return (a%b == 0)?b:gcd(b,a%b);
}

int prim(){
    for(int i = 1;i <= n;i++){
        dis[i] = 0;
        vis[i] = 0;
    }
    dis[1] = 0;int ans = 0;
    while(true){
        int v = 0;
        for(int i = 1;i <= n;i++)
            if(!vis[i]&&(v == 0||dis[i] > dis[v])) v = i;
        if(v == 0) break;
        vis[v] = 1;
        ans += dis[v];
        for(int i = 1;i <= n;i++)
            dis[i] = max(dis[i],gcd(v,i)&t);
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&t);
    printf("%d\n",prim());
    return 0;
}
