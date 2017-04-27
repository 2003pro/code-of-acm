#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x1,x2,y1,y2,vx1,vx2,vy1,vy2;
    double mi;
    double t;
    cin>>x1>>y1>>x2>>y2>>vx1>>vy1>>vx2>>vy2;
    double a = x1 - x2,b = vx1-vx2,c = y1-y2,d = vy1-vy2;
    double a1 = b*b + d*d,b1 = 2*(a*b+d*c),c1 = a*a+c*c;
    if(a1!=0) t = -b1/(2.0*a1);
    else  t = 0;
    if(t >= 0) mi = a1*t*t + b1*t + c1;
    else mi = c1;
    printf("%.15f\n",sqrt(mi));
    return 0;
}
