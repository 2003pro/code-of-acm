#include <cstdio>
#include <string>
#include <iostream>

struct Tree{
    int left,right;
    long long ma,sum;
}t[400003];

int a[100003];

using namespace std;

void build(int id,int l,int r);
void update(int id,int x,int v);
long long query(int id,int l,int r);

int main()
{
    int l,r,c,m,n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        scanf("%d",&m);
        for(int i=0;i<m;i++) {
                scanf("%d%d%d",&c,&l,&r);
                if(c==1) update(1,l,r);
                else printf("%lld\n",query(1,l,r));
        }
}

void build(int id,int l,int r){
    t[id].left = l;
    t[id].right = r;
    if(l == r) {
        t[id].sum = t[id].ma = a[l];
        return;
    }
    else {
        int mid = (l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id].sum = t[2*id].sum + t[2*id+1].sum;
        t[id].ma = max(t[2*id].ma,t[2*id+1].ma);
    }
}

void update(int id,int x,int v){
    if(t[id].left == t[id].right) t[id].sum = t[id].ma = v;
    else {
        int mid = (t[id].left + t[id].right)/2;
        if (x <= mid) update(2*id,x,v);
        else update(2*id+1,x,v);
        t[id].sum = t[2*id].sum + t[2*id+1].sum;
        t[id].ma = max(t[2*id].ma,t[2*id+1].ma);
    }
}

long long query(int id,int l,int r){
    if(t[id].left == l && t[id].right == r) return t[id].sum;
    else {
        int mid = (t[id].left + t[id].right)/2;
        if(r <= mid)return query(2*id,l,r);
        else if (l > mid) return query(2*id+1,l,r);
        else return query(2*id,l,mid)+query(2*id+1,mid+1,r);
    }
}
