#include<cstdio>
#include<algorithm>
using namespace std;

long long shu[4][50];
long long num[2000000];
int cnt=0,n,t;

void init()
{
    shu[0][0]=shu[1][0]=shu[2][0]=shu[3][0]=1;
    for(int i=1;;i++)
    {
        shu[0][i]=shu[0][i-1]*2;
        if(shu[0][i]>=1000000000)break;
    }
    for(int i=1;;i++)
    {
        shu[1][i]=shu[1][i-1]*3;
        if(shu[1][i]>=1000000000)break;
    }
    for(int i=1;;i++)
    {
        shu[2][i]=shu[2][i-1]*5;
        if(shu[2][i]>=1000000000)break;
    }
    for(int i=1;;i++)
    {
        shu[3][i]=shu[3][i-1]*7;
        if(shu[3][i]>=1000000000)break;
    }
}

void dfs(int id,long long ji)
{
    long long nji;
    for(int i=0;;i++)
    {
        if(ji>=1000000000&&i>0)break;
        nji=ji*shu[id][i];
        if(id==3)num[cnt++]=nji;
        else dfs(id+1,nji);
        if(shu[id][i]>=1000000000)break;
    }
}

long long erfen(int x)
{
    int l=0,r=cnt-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(num[mid]<x)l=mid+1;
        else r=mid;
    }
    return num[r];
}

int main()
{
    init();
    dfs(0,1);
    sort(num,num+cnt);
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%I64d\n",erfen(n));
    }
    return 0;
}
