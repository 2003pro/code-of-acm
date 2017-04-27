#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double a,s;
    while(scanf("%lf",&a)!=EOF){
        s=0;
        if(fmod(a,2)==0){printf("%.0f\n",floor(a/2));}
        else   {printf("%.0f\n",floor(a/2)-a);}
    }
    return 0;
}
