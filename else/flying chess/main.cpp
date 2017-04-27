#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T,m,n,i,j;
    int a[10001],b[10001];
    scanf("%d",&T);
    while(T--){
        int c=0;
        int d=0;
        int e=0;
        int f=0;
        int l[1000],m[1000];
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=0;i<n;i++)scanf("%d",&b[i]);
        for(i=0;i<n;i++){if(a[i]==6){c++;l[c-1]=i;}if(b[i]==6){d++;m[d-1]=i;}}
        for(i=0;i<c;i++){for(j=l[i];j<l[i+1])}
    }
    return 0;
}
