#include <iostream>
#include <cstdio>

using namespace std;

int n,m,ans;

int main()
{
    scanf("%d%d",&n,&m);
    n++;
    if(n>3)
    {
        ans=m-(n+1)/2;
    }
    else
    {
        if(n==2) ans=-1;
        if(n==3) ans=m;
    }
    printf("%d\n",ans);
    return 0;
}
