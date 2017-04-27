#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

double ans[300000];
char shu[1000000];

int main()
{
    freopen("out.txt","w",stdout);
    for(int i=0;i<1000000;i++)printf("0");
    for(int i=1;i<230000;i++) ans[i]=ans[i-1]+1.0/i/i;
    /*while(scanf("%I64d",&n)!=EOF)
    {
        if(n<230000)printf("%.5lf\n",ans[n]);
        else printf("1.64493\n");
    }*/
    return 0;
}
