#include <cstdio>
#include <cstdlib>

int main()
{
    int n,t;
    double ans = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {scanf("%d",&t);ans += 1.0*t/100 + (1.0-1.0*t/100)*(1.0*t/100);}
    printf("%.3f\n",ans);
    return 0;
}
