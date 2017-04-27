#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a;
int main()
{
    scanf("%I64d %I64d %I64d",&n,&m,&a);
    ll ans = 0;
    if(m/a > 0 && n/a > 0) ans = (m/a)*(n/a);
    else if(m/a == 0 && n/a == 0) ans = 1;
    if(m/a > 0 || n/a > 0){
        if(n%a != 0 && m%a != 0) ans += n/a + m/a + 1;
        else if(n%a != 0 && m%a == 0) ans += m/a;
        else if(m%a != 0 && n%a == 0) ans += n/a;
    }
    printf("%I64d\n",ans);
    return 0;
}
