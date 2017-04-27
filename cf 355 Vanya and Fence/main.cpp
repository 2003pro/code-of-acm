#include <iostream>
#include <cstdio>
#include <cstring>


int main()
{
    int n,h,t,ans = 0;
    scanf("%d%d",&n,&h);
    for(int i = 0;i < n;i++){
        scanf("%d",&t);
        ans += (t > h ? 2 : 1);
    }
    printf("%d\n",ans);
    return 0;
}
