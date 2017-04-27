#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,c,t1,t,cnt = 1;
    scanf("%d%d%d",&n,&c,&t1);
    for(int i = 1;i < n;i++){
        scanf("%d",&t);
        if(t-t1 <= c) cnt++,t1 = t;
        else cnt = 1,t1 = t;
    }
    printf("%d\n",cnt);
    return 0;
}
