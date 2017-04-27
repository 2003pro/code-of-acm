#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>


int main()
{
    std::priority_queue <int> q;
    int n,a[103],b[103],ma = 0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%d",&a[i]);
        b[a[i]] = i;
        if(ma < a[i]) ma = a[i];
    }
    int s = b[ma];
    int s1 = b[1];
    q.push(s);q.push(s1);q.push(n - 1 - s);q.push(n - 1 - s1);
    printf("%d\n",q.top());
    return 0;
}
