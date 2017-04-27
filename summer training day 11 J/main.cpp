#include <bits/stdc++.h>

using namespace std;
long long a[1000003],mod = 1000000007;
int main()
{
    a[0] = 1,a[1] = 1;
    for(long long i = 2;i <= 1000000;i++) a[i] = (i*a[i-1]+(i-1)*a[i-2])%mod;
    int T;
    scanf("%d",&T);
    for(int i = 1;i <= T;i++){
        long long n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",i,a[n-1]);
    }
    return 0;
}
