#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int T,i,a,b,s;
    scanf("%d",&T);
    while(T--)
    {
        a=0;
        b=0;
        scanf("%d %d",&a,&b);
         s=b;
         for(i=1;i<a;i++)
         {
             s=s-i*(2*a-(2*i-1));
         }
         if (s<a) printf("-1\n");
         else
         {
             for(i=1;i<a;i++) printf("%d ",i);
             printf("%d\n",s);
         }
    }
    return 0;
}
