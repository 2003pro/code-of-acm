#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,i;
    while(scanf("%d",&a)!=EOF){
        if(a<3) printf("1\n1\n");
        else if(a==3) printf("2\n1 3\n");
        else {
            printf("%d\n",a);
            if(a%2!=0) {for(i=0;i<a/2;i++){printf("%d ",2*i+2);}for(i=0;i<=a/2;i++){printf("%d ",2*i+1);}}
            else{for(i=0;i<a/2;i++){printf("%d ",2*i+2);}for(i=0;i<a/2;i++){printf("%d ",2*i+1);}}
        }
        printf("\n");
    }
    return 0;
}
