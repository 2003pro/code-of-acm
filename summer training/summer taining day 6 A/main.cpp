#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int main()
{
    int T,n,m,a[103],d[103];scanf("%d",&T);
    for(int j = 1;j <= T;j++){
        scanf("%d%d",&n,&m);ini(d,0);ini(a,0);
        for(int i = 0;i < n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i = 0;i < n-1;i++) d[i] = a[i+1]-a[i];
        sort(d,d+n-1);
        int sum = 0;
        for(int i = 0;i < n-1-m+1;i++) sum += d[i];
        printf("Case #%d: %d\n",j,sum);
    }
    return 0;
}
