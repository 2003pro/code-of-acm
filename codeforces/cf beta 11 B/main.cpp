#include <bits/stdc++.h>

using namespace std;
int ans,x;
void dfs(int a,int b){
    printf("%d %d\n",a,b);
    if(b == x){
        ans = min(ans,a);
        return;
    }
    if(abs(b) > x) return ;
    a++;
    dfs(a,b+a);
    dfs(a,b-a);
}
int main()
{
    scanf("%d",&x);
    ans = INT_MAX;
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}
