#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a[23],n,cnt = -1,sum,ans = 500;
char b[23],b1[23];

void dfs(int k){
    if(k == n && sum == 0) {
        cnt = 0;
        for(int i = 1;i < n ;i++) if(b[i] != b1[i]) cnt++;
        ans = min(ans,cnt);
        return ;
    }
    else if(k == n && sum != 0) return ;
    b1[k] = '+';
    sum += a[k+1];
    dfs(k+1);
    sum -= a[k+1];
    b1[k] = '-';
    sum -= a[k+1];
    dfs(k+1);
    sum += a[k+1];
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&a[1]);
    sum = a[1];
    for(int i = 2;i <= n;i++){
        scanf("%s %d",&b[i - 1],&a[i]);
    }
    dfs(1);
    printf("%d\n",min(ans,cnt));
}
