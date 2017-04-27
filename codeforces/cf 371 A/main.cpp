#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll l1,l2,r1,r2,k,ans,ar,al;
    scanf("%I64d %I64d %I64d %I64d %I64d",&l1,&r1,&l2,&r2,&k);
    if(r2 >= r1 && r1 >= l2 && l2 >= l1) al = l2,ar = r1;
    else if(r2 <= r1 && l2 >= l1) al = l2,ar = r2;
    else if(r2 <= r1 && r2 >= l1 && l1 >= l2) al = l1,ar = r2;
    else if(l1 > l2 && r2 > r1) al = l1,ar = r1;
    else {printf("0\n");return 0;}
    ans = ar - al + 1;
    if(k >= al && k <= ar) ans--;
    printf("%I64d\n",ans);
    return 0;
}
