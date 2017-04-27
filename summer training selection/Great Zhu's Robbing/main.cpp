#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

const int MA = 2000006;


long long s[MA];
int dp[MA];

int main()
{
    int  n,k,l,r;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) {
            scanf("%lld",&s[i]);
            s[i + n] = s[i];
    }
    for(int i = 2;i < n+k+1 ;i++) s[i] += s[i - 1];
    long long  m = INT_MIN;
    int head = 0;
    int rear = 0;
    s[0] = 0;
    dp[head] = 0;
    for(int i = 1;i <= n+k ;i++){
        if(s[i] - s[dp[head]] > m) {
            l = dp[head] + 1;
            r = i;
            m = s[i] - s[dp[head]];
        }
        while(head <= rear && s[i] < s[dp[rear]]) rear--;
        dp[++rear] = i ;
        if(dp[head] <= i - k ) head++;
    }
    if(r > n) r = r-n;
    printf("%lld %d %d\n",m,l,r);
    return 0;
}
