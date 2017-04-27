#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int T,n,m,i,a,b;
    int x[101];
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<101;i++){x[i]=0;}
        a=0;
        b=0;
        scanf("%d %d",&m,&n);
        if(n-(m-1)*9>9) printf("-1 -1\n");
        else if((n==1)&&(m>1)) printf("-1 -1\n");
        else
        {
            for(i=0;i<m;i++)
            {
                if(n>9){
                    x[i]=9;
                    n-=9;
                }
                else
                {
                    if(i+1==m) x[i]=n;
                    else if(i+2==m)
                    {
                         x[i]=n-1;
                         x[i+1]=1;
                         break;
                    }
                    else
                    {
                            x[i]=n-1;
                            i++;
                            for (;i<m-1;i++){x[i]=0;}
                            x[i]=1;
                            break;
                    }
                }
              }
              for(i=m-1;i>=0;i--)
              {
                  printf("%d",x[i]);
              }
              printf(" ");
              for(i=0;i<m;i++)
              {
                  printf("%d",x[i]);
              }



        }

    }
    return 0;
}
