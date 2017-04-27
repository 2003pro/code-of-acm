#include <cstdio>
#include <cstring>
#include <iostream>

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(x,y) (x + ((y - x)>>1))

struct Tree{
    int left,right;
    long long ma,lazy;
    int mid(){return MID(left,right);}
    void fun(long long tmp){
        lazy += tmp;
        ma += tmp;
    }
}t[400003];
int a[100003];



void Pushdown(int id){
    if(t[id].lazy){
        t[LL(id)].fun(t[id].lazy);
        t[RR(id)].fun(t[id].lazy);
        t[id].lazy = 0;
    }
}
void Pushup(int id){
    t[id].ma = std::max(t[LL(id)].ma,t[RR(id)].ma);
}

void build(int id,int l,int r){
    t[id].left = l;
    t[id].right = r;
    if(l == r) {
        t[id].ma = a[l];
        t[id].lazy = a[l];
        return;
    }
    else {
        int mid = t[id].mid();
        build(LL(id),l,mid);
        build(RR(id),mid+1,r);
        t[id].ma = std::max(t[LL(id)].ma,t[RR(id)].ma);
    }
}
void update(int s,int e,int id,int v){
    int l = t[id].left,r = t[id].right;
    if(s <= l&&r <= e) t[id].fun(v);
    else {
        Pushdown(id);
        int mid = t[id].mid();
        if(s <= mid ) update(s,e,LL(id),v);
        if(e > mid) update(s,e,RR(id),v);
        Pushup(id);
    }
}
long long query(int s,int e,int id){
    int l = t[id].left,r = t[id].right;
    if(s <= l&&r <= e) return t[id].ma;
    else {
        Pushdown(id);
        int mid = t[id].mid();
        long long s1 = 0,s2 = 0;
        if(s <= mid ) s1 = query(s,e,LL(id));
        if(e > mid) s2 = query(s,e,RR(id));
        Pushup(id);
        return std::max(s1,s2);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int l,r,c,m,n = 0;
        scanf("%d",&m);
        memset(a,0,sizeof(a));
        for(int j = 0 ;j < 400003;j++) t[j].left = t[j].right = t[j].lazy = t[j].ma = 0;
        build(1,1,100003);
        for(int i=0;i<m;i++) {
                scanf("%d%d%d",&l,&r,&c);
                if(r + 1 > n) n = r + 1;
                update(l+1,r+1,1,c);
        }
        printf("%lld\n",query(1,n,1));
    }
}




