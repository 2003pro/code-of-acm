#include <bits/stdc++.h>

using namespace std;
int n,t1,t2,t3;
int main()
{
    while(scanf("%d%d%d%d",&n,&t1,&t2,&t3) && (n + t1 + t2 + t3)){
        double sum = 0;
        for(int i = 0;i < n;i++) sum += 1.0*i;
        double ans = (1.0*sum/n);
        ans += 1.0*n*3;
        if(t2 >= t1) ans += 1.0*(t2 - t1);
        else ans += 1.0*(n - abs(t1 - t2));
        if(t2 >= t3) ans += 1.0*(t2 - t3);
        else ans += 1.0*(n - abs(t3 - t2));
        printf("%.3f\n",ans);
    }
    return 0;
}
