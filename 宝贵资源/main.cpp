#include <iostream>
#include <cstdio>
#include  <cstring>

using namespace std;

long long sort1(long long a[], int n){
    for(int i =0 ; i< n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] < a[j+1])
            {
                long long t = a[j] ;
                a[j] = a[j+1] ;
                a[j+1] = t;
            }
        }
    }
    return a[0];
} ;

long long sort2(long long a[], int n){
    for(int i =0 ; i< n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] < a[j+1])
            {
                long long t = a[j] ;
                a[j] = a[j+1] ;
                a[j+1] = t;
            }
        }
    }
    return a[n-1];
} ;

int main()
{
    int T,k,c;
    long long x[1001],y[1001];
    long long a,b,a1,b1;
    scanf("%d",&T);
    k=0;
    c=T;
    while(T--)
    {
        scanf("%lld %lld",&x[k],&y[k]);
        k++;
    }
    a=sort1(x,c);
    b=sort1(y,c);
    a1=sort2(x,c);
    b1=sort2(y,c);
    a=a-a1;
    b=b-b1;
    if(a<b) a=b;
    printf("%lld\n",a*a);
    return 0;
}


