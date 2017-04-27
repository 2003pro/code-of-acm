#include <iostream>
#include <cstdio>
#include <cstring>

int x3,y3;
int findl(int x,int t,const char* a);
int findr(int x,int t,const char* a);
int findu(int x,int t,const char* a);
int findd(int x,int t,const char* a);

using namespace std;

int main()
{
    int T,x2,y2,x1,y1,a,b,t;
    char str[100001];
    scanf("%d",&T);
    while(T--)
    {
        x3=0;
        y3=0;
        x2=0;
        y2=0;
        a=0;
        b=0;
        x1=0;
        y1=0;
        str[100001]={'\0'};
        scanf("%d %d %d",&x2,&y2,&t);
        getchar();
        gets(str);
        if(x2>=0)  {
            x1=x2;
            a=findr(x1,t,str);
        }
        else {
            x1=-x2;
            a=findl(x1,t,str);
        }
        if(y2>=0){
            y1=y2;
            b=findu(y1,t,str);
        }
        else{
            y1=-y2;
            b=findd(y1,t,str);
        }
        if ((!a)||(!b)) printf("-1");
        else printf("%d",x3+y3);
    }
    return 0;
}

int findl(int x,int t,const char* a)
{
    int cnt=0;
    for(int i=0;i<t;i++)
    {
        if (a[i]=='L') cnt++;
        x3=cnt;
        if (cnt==x) return 1;
    }
    return -1;
};
int findr(int x,int t,const char* a)
{
    int cnt=0;
    for(int i=0;i<t;i++)
    {
    if (a[i]=='R') cnt++;
    x3=cnt;
    if (cnt==x) return 1;
    }
    return -1;
};
int findu(int x,int t,const char* a)
{
    int cnt=0;
    for(int i=0;i<t;i++)
    {
    if (a[i]=='U') cnt++;
    y3=cnt;
    if (cnt==x) return 1;
    }
    return -1;
};
int findd(int x,int t,const char* a)
{
    int cnt=0;
    for(int i=0;i<t;i++)
    {
    if (a[i]=='D') cnt++;
    y3=cnt;
    if (cnt==x) return 1;
    }
    return -1;
};
