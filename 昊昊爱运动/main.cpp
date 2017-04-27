#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
      int Q,l,r,n,m,i,cnt;
      int a[2001];
      int b[101]={0};
      scanf("%d %d",&n,&m);
      for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
       }
       scanf("%d",&Q);
       while(Q--)
       {
            for(i=0;i<101;i++){b[i]=0;}
            cnt=0;
            l=0;
            r=0;
            scanf("%d %d",&l,&r);
            for(i=l-1;i<r;i++)
            {
                b[a[i]]++;
            }
            for(i=0;i<101;i++)
            {
                if(b[i]!=0) cnt++;
            }
            printf("%d\n",cnt);
        }
        return 0;
}
