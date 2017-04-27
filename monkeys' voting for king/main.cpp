#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T,a,b,i,m,n;
    int c[101];
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        if(b==1) printf("%d\n",a);
        else {for(i=0;i<a;i++){
                c[i]=(i+1)%a;
            }
            m=0;
            while(m!=c[m]){
                for(i=1;i<b;i++){
                    n=m;
                    m=c[m];
                }
                c[n]=c[m];
                m=c[n];
            }
            printf("%d\n",m+1);
        }
    }
    return 0;
}
