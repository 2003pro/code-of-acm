#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int c[10]={2,7,2,3,3,4,2,5,1,2};
    int a[2],i,d;
    char b[2];
    for(i=0;i<2;i++){scanf("%c",&b[i]);a[i]=b[i]-'0';}
    printf("%d\n",c[a[0]]*c[a[1]]);
    return 0;
}
