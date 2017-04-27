#include <stdio.h>
#include <stdlib.h>
#define lid (id<<1)
#define rid (id<<1|1)

struct note
{
    int l,r;
    long long sum;
};
struct note node[4*100005];

int a[100005];
void push_up(int id)
{
    node[id].sum=node[lid].sum+node[rid].sum;
}

void initial(int id,int l,int r)
{
    node[id].l=l;
    node[id].r=r;
    if(l==r)
    {
        node[id].sum=a[l];
        return;
    }
    int z=(l+r)>>1;
    initial(lid,l,z);
    initial(rid,z+1,r);
    push_up(id);
}
void update(int id,int x,int v)
{
    if(node[id].l==node[id].r)
    {
        node[id].sum=v;
        return;
    }
    int mid=(node[id].l+node[id].r)>>1;
    update(x<=mid?lid:rid,x,v);
    push_up(id);
}

long long query(int id,int l,int r)
{
    if(node[id].l==l&&node[id].r==r)
        return node[id].sum;
    int mi=(node[id].l+node[id].r)>>1;
    if(r<=mi) return query(lid,l,r);
    if(l>mi) return query(rid,l,r);
    return query(lid,l,mi)+query(rid,mi+1,r);
}

int main(void)
{
    int i,n,m,j;
    int b[100005][3];
    scanf("%d",&n);
    for(i=1;i<n+1;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    initial(1,1,n);
    for(i=0;i<m;i++)
    {
        if(b[i][0]==1)
        {
            update(1,b[i][1],b[i][2]);
        }
        else if(b[i][0]==2)
        {
            printf("%lld\n",query(1,b[i][1],b[i][2]));
        }
    }
    return 0;
}

