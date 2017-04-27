#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 6

int k=0,i=0;
char map[size][size];

void path_print(int x,int y,int x1,int y1)
{
    i=x;
    k=y;
    printf("[%d][%d]->",x,y);
    if(x<x1)
    {
        for(i=x;i!=x1;)
        {
            i++;
            if(i==x1&&k==y1) printf("[%d][%d]",i,k);
            else printf("[%d][%d]->",i,y);
        }
    }
    else if(x>x1)
    {
        for(i=x;i!=x1;)
        {
            i--;
            if(i==x1&&k==y1) printf("[%d][%d]",i,k);
            else printf("[%d][%d]->",i,y);
        }
    }
    x=i;
    if(y<y1)
    {
        for(k=y;k!=y1;)
        {
            k++;
            if(i==x1&&k==y1) printf("[%d][%d]",i,k);
            else printf("[%d][%d]->",x,k);
        }
    }
    else if(y>y1)
    {
        for(k=y;k!=y1;)
        {
            k--;
            if(i==x1&&k==y1) printf("[%d][%d]",i,k);
            else printf("[%d][%d]->",x,k);
        }
    }
}

int main()
{
    int j,l;
    int sx=0,sy=0;
    int endx=0,endy=0;
    for (j=0;j<size;j++)
    {
        scanf("%s",map[j]);
    }

    for(j=0;j<size;j++)
    {
        for(l=0;l<size;l++)
        {
            if (map[j][l]=='1')
            {
                sx=j;
                sy=l;
            }
            if (map[j][l]=='2')
            {
                endx=j;
                endy=l;
            }
        }
    }
    if(sx==0&&sy==0) printf("NO");
    else if(sx==0&&sy==5) printf("NO");
    else if(sx==5&&sy==5) printf("NO");
    else if(sx==5&&sy==0) printf("NO");
    else if(sx==0||sx==5)
    {
        if(endx!=sx) printf("NO");
    }
    else if(sy==0||sy==5)
    {
        if(endy!=sy) printf("NO");
    }
    else path_print(sx,sy,endx,endy);
    return 0;
}
