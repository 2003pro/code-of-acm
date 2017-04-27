#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef struct node{
    int x,y;
}Node;
bool cmp(Node a,Node b){return a.x<b.x;}

int main()
{
    int a,b,i,s,m,j;
    Node c[101];
    while(scanf("%d %d",&a,&b)!=EOF){
        for(i=0;i<a;i++){scanf("%d",&c[i].x);c[i].y=i+1;}
        sort(c,c+a,cmp);
        s=b;
        m=0;
        for(i=0;i<a;i++){
            m++;
            s=s-c[i].x;
            if(s<0&&m==1) {printf("0");break;}
            if(s==0) {
                    printf("%d\n",m);
                    for(j=0;j<m;j++)printf("%d ",c[j].y);
                    break;
            }
            else if(s<0){
                    m--;
                    printf("%d\n",m);
                    for(j=0;j<m;j++)printf("%d ",c[j].y);
                    break;
            }
        }
        if(s>0){printf("%d\n",m);for(j=0;j<m;j++)printf("%d ",c[j].y);}
        printf("\n");
    }
    return 0;
}
