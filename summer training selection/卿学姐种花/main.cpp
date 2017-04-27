#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i++)
using namespace std;
typedef long long ll;
const int N = 1e4+3;
const ll mod = 772002+233;
ll lazy[N],a[N],num[N],ed[N];
int main()
{
    int x,n,q,f;ll y;scanf("%d%d",&n,&q);
    rep(i,1,n) {scanf("%lld",&a[i]);a[i] = a[i]%mod;}
    rep(i,1,q){
        scanf("%d",&f);
        if(f == 1) {
            scanf("%d%lld",&x,&y);
            lazy[x] += y;
            num[x]++;
            ed[min(1LL*n+1,1LL*x+y)]++;
        }
        else {
            scanf("%d",&x);
            ll num1 = 0,add = 0;
            rep(j,1,x){
                add += lazy[j];
                num1 += num[j];
                num1 -= ed[j];
                lazy[j] = num[j] = ed[j] = 0;
                a[j] = (a[j]+add) % mod;
                add -= num1;
            }
            lazy[x+1] += add;num[x+1] += num1;
            printf("%lld\n",a[x]);
        }
    }
    return 0;
}
