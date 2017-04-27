#include <cstdio>
#include <iostream>

using namespace std;

long long cac(int a);

int main()
{
    int a;
    while(scanf("%d",&a)!=EOF){
        printf("%lld\n",cac(a));
    }
}
long long cac(int a){
    long long c[6],i=0,j;
    long long d[6]={2,4,16,256,65536,4294967296};
    long long res=1;
    for(i=0;a>0;i++){
        c[i]=a%2;
        a/=2;
    }
    for(j=0;j<i;j++){
        if(c[j]!=0)res*=c[j]*d[j];
    }
    return res;
}
