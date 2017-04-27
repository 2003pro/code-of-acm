#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct side{
    int s,e,w;
}ss[40005];

int T,N,M,K,a[205],fx,fy,d,x;


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
int kruskal(){
    int cnt = 0;
    sort(ss,ss+M+K,cmp);
    for(int i=0;i<M+K;i++){
        fx=finds(ss[i].s);
        fy=finds(ss[i].e);
        if(fx!=fy){
            cnt+=ss[i].w;
            unions(ss[i].s,ss[i].e);
        }
    }
    return cnt;
}
int main()
{
    for(int i=0;i<205;i++) ss[i].w=0x7fffffff;
    scanf("%d",&T);
    for(int j = 1;j <= T;j++){
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<K;i++){scanf("%d",&x);ss[M+i].s = N+1,ss[M+i].e = x,ss[M+i].w = 0;}
        for(int i=0;i<M;i++) scanf("%d%d%d",&ss[i].s,&ss[i].e,&ss[i].w);
        for(int i=1;i<=N+1;i++) a[i]=i;
        printf("Case #%d: %d\n",j,kruskal());
    }
    return 0;
}


