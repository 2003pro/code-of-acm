#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int lg[N],a[N];
struct node{
    int l,r,ma,maid;
}tree[4*N];
void build(int id,int l,int r){
    tree[id].l = l,tree[id].r = r;
    if(l == r) tree[id].ma = 0,tree[id].maid = l;
    else {
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id].ma = max(tree[2*id].ma,tree[2*id+1].ma);
        tree[id].maid = (tree[id].ma == tree[2*id].ma) ? tree[id*2].maid : tree[id*2+1].maid;
    }
}
void update(int id,int pos,int val){
    if(tree[id].l == tree[id].r) tree[id].ma += val;
    else {
        int mid = (tree[id].l + tree[id].r)/2;
        if(pos <= mid) update(id*2,pos,val);
        else update(id*2+1,pos,val);
        tree[id].ma = max(tree[id*2].ma,tree[id*2+1].ma);
        tree[id].maid = (tree[id].ma == tree[2*id].ma) ? tree[id*2].maid : tree[id*2+1].maid;
    }
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n,q;
        memset(lg,0,sizeof(lg));
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&q);
        build(1,1,n);
        int x,p,ma = 0,mpa = 1;
        lg[0] = 1;
        for(int i = 1;i <= q;i++){
            scanf("%d%d",&x,&p);
            update(1,x,p);
            lg[i] = tree[1].maid;
        }
        int tt = lg[q];
        while(lg[q] == tt&&q >= 0)q--;
        printf("%d\n",q+1);
    }
    return 0;
}
