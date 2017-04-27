#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[100003];
int main()
{
    ll t,t1;
    int n;
    scanf("%d",&n);scanf("%I64d",&t);
    for(int i = 0;i < n-2;i++){
        scanf("%I64d",&t1);
        a[i] = t1 + t;
        t = t1;
    }
    scanf("%I64d",&a[n-1]);
    a[n-2] = t1 + a[n-1];
    for(int i = 0;i < n;i++) printf("%I64d ",a[i]);
    printf("\n");
    return 0;
}
