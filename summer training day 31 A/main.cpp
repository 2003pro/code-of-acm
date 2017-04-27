#include <bits/stdc++.h>
using namespace std;
const int N = 100003;
int a[N],sum[N],b[N];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n,m,k,sum1 = 0;scanf("%d%d%d",&n,&m,&k);
        for(int i = 0;i < n;i++) scanf("%d",&a[i]);
        b[0] = (m - a[0]) >= 0?(m - a[0]):0;sum[0] = b[0];sum1 = b[0];
        for(int i = 1;i < k;i++){
            int nt = (m - a[i]) >= 0?(m - a[i]):0;
            b[i] = (nt - sum[i-1]) >= 0?(nt - sum[i-1]):0;
            sum1 += b[i];sum[i] = sum1;
        }
        for(int i = k;i < n;i++){
            int nt = (m - a[i]) >= 0?(m - a[i]):0;
            b[i] = (nt - (sum[i-1] - sum[i-k])) >= 0?(nt - (sum[i-1] - sum[i-k])):0;
            sum1 += b[i];sum[i] = sum1;
        }
        int ans = 0;
        for(int i = 0;i < n;i++) ans += b[i];
        printf("%d\n",ans);
    }
    return 0;
}
