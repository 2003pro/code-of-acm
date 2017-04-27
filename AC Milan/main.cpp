#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct job{
        int v,a;
}b[1003];
bool comp(job c,job b){
    if(c.v==b.v) return c.a<b.a;
    else return c.v<b.v;
}

int main()
{
    int T,i,co=0,t=0,x=0,m[1003];
    memset(m,0,1003);
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d",&b[i].v,&b[i].a);
    }
    sort(b,b+T,comp);
    for(i=0;i<T-1;i++){
        if(x<b[i].v)x=b[i].v+b[i].a;
        else x+=b[i].a;
        if(b[i+1].v-x-b[i].a>0)co+=b[i+1].v-x-b[i].a;
    }
    printf("%d\n",co+b[0].v);
}
