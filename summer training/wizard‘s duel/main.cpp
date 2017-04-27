#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double l,p,q;
    while(scanf("%lf %lf %lf",&l,&p,&q)!=EOF){
        printf("%.4f\n",p*(l/(p+q)));
    }
    return 0;
}
