#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a,b[303],i,j,c[301][301],t;
    char s;
    while(scanf("%d",&a)!=EOF){
        for(i=0;i<a;i++) {scanf("%d",&b[i]);}
        getchar();
        for(i=0;i<a;i++){ for(j=0;j<a;j++) {scanf("%c",&s);c[i][j]=s-'0';}getchar();}
        for(i=0;i<a;i++){ for(j=0;j<a;j++) {printf("%d ",c[i][j]);}printf("\n");}
        for(i=0;i<a;i++){
                for(j=0;j<a;j++) {
                        if(c[i][j]==1) {
                            if(b[i]<b[j]&&i>j){t=b[i];b[i]=b[j];b[j]=t;}
                            else if(b[j]<b[i]&&j>i){t=b[j];b[j]=b[i];b[i]=t;}
                        }
                }
                for(int l=0;l<a;l++) printf("%d ",b[l]);
                printf("\n");
        }
        for(int k=0;k<a;k++) printf("%d ",b[k]);
        printf("\n");
    }
    return 0;
}
