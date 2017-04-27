#include <bits/stdc++.h>

using namespace std;
const int N = 100003;
int n,a[N],b[N];
int main()
{
    int l = 0, r = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&a[i],&b[i]);
        l += a[i],r += b[i];
    }
    int an = 0 , t = abs(l-r),l1,r1;
    for(int i = 1;i <= n;i++){
        l1 = l,r1 = r;
        l1 -= a[i],r1 -= b[i];
        l1 += b[i],r1 += a[i];
        if(t < abs(l1-r1)) t = abs(l1-r1),an = i;
    }
    printf("%d\n",an);
    return 0;
}
