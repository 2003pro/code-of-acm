#include <iostream>
#include <cstdio>
#include  <cstring>
#include <cmath>
using namespace std;

int main()
{
    double x1,x2,y1,y2,x,y;
    double d,r;
    while(scanf("%lf %lf %lf %lf %lf",&r,&x1,&y1,&x2,&y2)!=EOF){
        x=x1-x2;
        y=y1-y2;
        d=sqrt(x*x+y*y);
        printf("%.0f\n",ceil(d/2/r));
    }
}
