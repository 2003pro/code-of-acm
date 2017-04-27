#include <bits/stdc++.h>

using namespace std;
int n,a[103],dp[103][103];
int calin(int x){
    int cnt = 0;
    while(x%2 == 0&&x != 0){
        cnt++;
        x /= 2;
    }
    return cnt;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(a[j] >= a[i]) dp[i][j] = dp[i-1][j];
            }
            dp[i][i] =
        }
        int mx = 0;
        printf("%d\n",mx);
    }
    return 0;
}
