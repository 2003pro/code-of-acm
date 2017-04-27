#include <iostream>
#include <cstdio>
int n;
using namespace std;
int test(int a);

int main()
{
    int a,i,b,c;
    scanf("%d",&a);
    n=a;
    for(i=0;i<a;i++){
        scanf("%d",&b);
        c=test(b);
    }
    printf("%d %d\n",n,c);
    return 0;
}
int test (int a){
    static int m=0;
    m++;
    int i;
    if(a<2) n--;
    for(i=2;i<=a/2;i++){
        if(a%i==0) {n--;break;}
    }
    return m;
}
