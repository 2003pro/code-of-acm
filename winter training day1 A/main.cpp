#include <bits/stdc++.h>

using namespace std;
#define ini(x,y) memset(x,y,sizeof(x));
typedef long long ll;
const ll mod = 1e9 + 7;
int a[153],b[153];
ll dp1[15003],dp2[15003];
int main()
{
    int T,n,m,k,w;scanf("%d",&T);
    while(T--){
        ini(dp1,0);ini(dp2,0);
        dp1[0] = 1;dp2[0] = 1;
        scanf("%d%d%d%d",&n,&m,&k,&w);
        for(int i = 0;i < n;i++){scanf("%d",&a[i]);}
        for(int i = 0;i < m;i++){scanf("%d",&b[i]);}
        for(int i = 0;i < n;i++){
            for(int j = w;j >= a[i];j--){
                dp1[j] = (dp1[j]+dp1[j-a[i]])%mod;
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = w;j >= b[i];j--){
                dp2[j] = (dp2[j]+dp2[j-b[i]])%mod;
            }
        }
        int s1 = 0,s2 = w,j,i;
        ll sum = 0;
        for(i = 0;i <= w;i++){
            j = w - i;
            if(abs(i-j) <= k) sum = (sum + dp1[i]*dp2[j])%mod;
        }
        printf("%d\n",sum);
    }
    return 0;
}
