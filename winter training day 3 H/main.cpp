#include <bits/stdc++.h>

using namespace std;
int jl(double l,double w,double t){
    if(l >= 125 && w >= 90 && t >= 0.25) {
        if(l <= 290 && w <= 155 && t <= 7 ) return 1;
        else if(l <= 380 && w <= 300 && t <= 50 ) return 2;
        else if(l + 2*(w+t) <= 2100 ) return 3;
    }
    return -1;
}

int main()
{
    double a[3];
    while(scanf("%lf%lf%lf",&a[0],&a[1],&a[2])!=EOF){
        if(!a[0]) break;
        sort(a,a+3);
        double l = a[2],w = a[1],t = a[0];int a1 = jl(l,w,t);
        if(a1 == 1) printf("letter\n");
        else if(a1 == 2) printf("packet\n");
        else if(a1 == 3) printf("parcel\n");
        else printf("not mailable\n");
    }
    return 0;
}
