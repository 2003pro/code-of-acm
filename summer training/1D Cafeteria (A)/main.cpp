#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,a[100],b[100],ans = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&a[i],&b[i]);
        ans += (b[i] - a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
