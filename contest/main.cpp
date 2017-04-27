#include <iostream>
#include <cstdio>

using namespace std;

double max1(double p,double t);

int main()
{
        double a,b,c,d,x,y;
        while(scanf("%lf %lf %lf %lf",&a,&b,&c,&d)!=EOF){
            x=max1(a,c);
            y=max1(b,d);
            if(x>y) printf("Misha\n");
            else if(x<y) printf("Vasya\n");
            else if(x==y) printf("Tie\n");
        }
        return 0;
}
double max1(double p,double t){
        int a,b;
        a=p*3/10;
        b=p-p*t/250;
        return max(a,b);
}
