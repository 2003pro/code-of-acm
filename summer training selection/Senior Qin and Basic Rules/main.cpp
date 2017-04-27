#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node{
    int l,r;
    long long lazy,sum;
    void fun(long long tmp){
        lazy += tmp;
        sum += (r - l + 1)*tmp;
    }
}tree[4*100003];
struct opera{
    int l,r,d;
}operat[4*100003];
int w[200003];
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MM(a,b) (a + ((b-a)>>1))

void pushdown(int ind){
    if(tree[ind].lazy){
        tree[LL(ind)].fun(tree[ind].lazy);
        tree[RR(ind)].fun(tree[ind].lazy);
        tree[ind].lazy = 0;
    }
}

void pushup(int ind){
    tree[ind].sum = tree[LL(ind)].sum + tree[RR(ind)].sum;
}

void update(int st,int ed,int ind,int val){
    int l1 = tree[ind].l;
    int r1 = tree[ind].r;
    if(st >= l1&&r1 <= ed) tree[ind].fun(val);
    else {
        pushdown(ind);
        int mid = MM(tree[ind].l,tree[ind].r);
        if(st <= mid) update(st,ed,LL(ind),val);
        else if(ed > mid) update(st,ed,RR(ind),val);
        pushup(ind);
    }
}

long long query(int st,int ed,int ind){
    int l1 = tree[ind].l;
    int r1 = tree[ind].r;
    if(st >= l1&&r1 <= ed) return tree[ind].sum;
    else {
        pushdown(ind);
        int mid = MM(tree[ind].l,tree[ind].r);
        long long sum1 = 0,sum2 = 0;
        if(st <= mid) sum1 = query(st,ed,LL(ind));
        else if(ed > mid) sum2 = query(st,ed,RR(ind));
        pushup(ind);
        return sum1 + sum2;
    }
}
void build(int ind,int l1,int r1){
    tree[ind].l = l1;
    tree[ind].r = r1;
    if(l1== r1) {
        tree[ind].sum = a[l];
        return;
    }
    else {
        int mid = MM(l1,r1);
        build(LL(ind),l1,mid);
        build(RR(ind),mid+1,r1);
        tree[ind].sum = tree[LL(ind)].sum,t[RR(ind)].sum);
    }
}

int main()
{
    memset(w,0,sizeof(w));
    int Q,cnt = 0,ct = 0,N,j = 0;
    scanf("%d%d",&N,&Q);
    for(int i = 0;i < Q;i++){
        scanf("%d%d%d",&operat[i].d,&operat[i].l,&operat[i].r);
        w[j++] = operat[i].l;
        w[j++] = operat[i].r;
    }
    sort(w,w+j);
    int len = unique(w,w+j) - w;
    build(1,1,len);
}

