#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct side{
    int s,e,w;
}ss[1000005];

int T,N,M,a[1005],fx,fy;

void kruskal(){
    int cnt = 0;
    sort(ss,ss+M,cmp);
    for(int i=0;i<M;i++){
        fx=finds(ss[i].s);
        fy=finds(ss[i].e);
        if(fx!=fy){
            cnt+=ss[i].w;
            unions(ss[i].s,ss[i].e);
        }
    }
    printf("%d\n",cnt);
}

int finds(int x){
    if(a[x]!=x) return finds(a[x]);
    else return x;
}

void unions(int x,int y){
    int ax = finds(x);
    int ay = finds(y);
    a[ay] = ax;
}
bool cmp(side x,side y){
    return x.w<y.w;
}

int main()
{
    for(int i=0;i<1000005;i++) ss[i].w=0x7fffffff;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++) scanf("%d%d%d",&ss[i].s,&ss[i].e,&ss[i].w);
        for(int i=0;i<N;i++) a[i]=i;
        kruskal();
    }
    return 0;
}


