#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void agree(int m,int b[])
{
    int a,d,c;
    d=0;
    c=0;
    for(int i=0;i<m;i++)
    {
        a=b[m]-b[i];
        if(a>0) d+=a;
        else c+=a;
    }
    if (d==(-c)) printf("Next time\n");
     else if(d>(-c))printf("Keep some distance from me\n");
     else if(d<(-c))   printf("I agree\n");
};

int main()
{
    int n,e,m,i;
    scanf("%d %d",&n,&m);
    char a[100002];
    int b[100002];
    int c[100002];
    for(i=0;i<=n;i++)
    {
        scanf("%c",&a[i]);
        sscanf(&a[i],"%d",&b[i]);
    }
    for(int k=0;k<m;k++)
    {
    scanf("%d",&c[k]);
    e=c[k];
    agree(e,b[100002]);
    }
    return 0;
}
