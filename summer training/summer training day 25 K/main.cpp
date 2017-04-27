#include <bits/stdc++.h>

using namespace std;
int a[303],b[303];
int main()
{
    int n,sum = 0;scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    for(int i = 0;i < n;i++) scanf("%d",&b[i]);
    sort(a,a+n);sort(b,b+n);
    for(int i = 0;i < n;i++) sum += abs(a[i]-b[i]);
    double ans = 1.0*sum/n;
    printf("%.8f\n",ans);
    return 0;
}
