#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    double a[5];
    double sum=0;
    a[0]=(20*19*18*17)/24;
    a[1]=(5*20*19*18)/6;
    a[2]=(20*19*5*4)/4;
    a[3]=200;
    a[4]=5;
    double c=0;
    double b=a[0]+a[1]+a[2]+a[3]+a[4];
    for(int i=0;i<4;i++){
        sum+=a[i];
        c=sum/b;
        printf("%f\n",c);
    }
    int l=864-593;
    int m=593-323;
    printf("%d %d",l,m);
    return 0;
}
