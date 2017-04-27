#include <iostream>
#include <cstdio>
#include  <cstring>

using namespace std;

int main()
{
    int n,a1,i;
    a1=0;
    int a[2001];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) a1++;
    }
    if(n==1||n==2) printf("1\n");
    else if(a1>(n%2)) printf("%d\n",n%2);
    else if((n%2)==0) printf("%d\n",a1+2*(n%2-a1)-1);
    else printf("%d\n",a1+2*(n%2-a1));
    return 0;
}
