#include<iostream>
#include<stdio.h>
using namespace std;

int flag;
int n,m;
int Min[120];
int Max[120];
void getmin()
{
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(i==1)Min[i]=1;
        else Min[i]=0;
        sum += Min[i];
    }
    sum = m - sum;
    for(int i=n;i>=1;i--)
    {
        int T = min(sum,9-Min[i]);
        sum -= T;
        Min[i] += T;
    }
    if(Min[1]==0)flag = 1;
}
void getmax()
{
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        Max[i]=9;
        sum+=Max[i];
    }
    sum = sum - m;
    for(int i=n;i>=1;i--)
    {
        int T = min(sum,Max[i]);
        sum-=T;
        Max[i]-=T;
    }
    if(Max[1]==0)flag = 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);
        flag = 0;
        if(n==1&&m==0)
        {
            printf("0 0\n");
            continue;
        }
        if(n*9<m)
        {
            printf("-1 -1\n");
            continue;
        }
        getmin(),getmax();
        if(flag)
        {
            printf("-1 -1\n");
            continue;
        }
        for(int i=1;i<=n;i++)
            printf("%d",Min[i]);
        printf(" ");
        for(int i=1;i<=n;i++)
            printf("%d",Max[i]);
        printf("\n");
    }
}
