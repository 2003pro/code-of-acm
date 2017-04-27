#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int i,a;
    double b,c[1003],d[1003];
    while(scanf("%d %lf",&a,&b)!=EOF){
        for(i=0;i<a;i++) scanf("%lf",&c[i]);
        sort(c,c+a);
        d[a]=0;
        d[a-1]=0;
        if(c[0]!=0) d[a-1]=c[0];
        if(c[a-1]!=b) d[a]=b-c[a-1];
        for(i=0;i<a-1;i++){
                d[i]=(c[i+1]-c[i])/2;
        }
        sort(d,d+a+1);
        double e=d[a];
        printf("%.10f\n",e);
    }
    return 0;
}
