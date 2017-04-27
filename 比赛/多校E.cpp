#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,t;
bool is[110];

int main()
{
    scanf("%d",&t);
    for(int o=1;o<=t;o++)
    {
        scanf("%d%d",&n,&m);
        int l,r;
        memset(is,0,sizeof(is));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l,&r);
            for(int j=l;j<=r;j++)
            {
                is[j]=1;
            }
        }
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            if(is[i])cnt++;
        }
        printf("%d\n",min(n,cnt));
    }
    return 0;
}
