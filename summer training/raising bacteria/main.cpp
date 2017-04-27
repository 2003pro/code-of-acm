#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
double re(double a);

int main()
{
    double a,c;
    int i;
    while(scanf("%lf",&a)!=EOF){
        c=re(a);
        for(i=1;c!=0;i++) c=re(c);
        printf("%d\n",i);
    }
    return 0;
}
double re(double a){
        double i;
        double b;
        for(i=0;i<32;i++){
            b=a-pow(2,i);
            if(b<0) return a-pow(2,i-1);
            else if(b==0) return 0;
        }
}
