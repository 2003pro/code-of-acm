#include <bits/stdc++.h>

using namespace std;
const int N = 1e4+3;
int a[N],vis[N];
int main()
{
    int n,num = 0;scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++){
        if(a[a[i]] == i && !vis[i] && !vis[a[i]]) {
            num++;
            vis[i] = 1;
            vis[a[i]] = 1;
        }
    }
    printf("%d\n",num);
    return 0;
}
