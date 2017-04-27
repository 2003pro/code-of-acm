#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
double n,t1,t2,t3;

int main()
{
    while(scanf("%lf%lf%lf%lf",&n,&t1,&t2,&t3) && (n + t1 + t2 + t3)){
        double x = 9.0,y = 4.0,z = 4.0;double mi,mx;
        double tt1 = t1 > 0 ? t1 - 0.5:0;double tt2 = t2 > 0 ? t2 - 0.5:0;double tt3 = t3 > 0 ? t3 - 0.5:0;
        mi = round(tt1*x + tt2*y + tt3*z);
        double t11 = (t1 < 1000 ? t1 + 0.49:1000);double t22 =  t2 < 1000 ? t2 + 0.49:1000;double t33 = t3 < 1000 ? t3 + 0.49:1000;
        mx = round(t11*x + t22*y + t33*z);
        mx = (mx <= 10000 ? mx : 10000);
        if(n >= mi && n <= mx) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
