#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a[5];
bool fun(int n){
    if(n==1){
        if(fabs(a[0]-24)<1e-6)return true;
        else return false;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double x1=a[i];
            double x2=a[j];
            a[j]=a[n-1];
            a[i]=x1+x2;if(fun(n-1))return true;
            a[i]=x1*x2;if(fun(n-1))return true;
            a[i]=x1-x2;if(fun(n-1))return true;
            a[i]=x2-x1;if(fun(n-1))return true;
            if(x2){a[i]=x1/x2;if(fun(n-1))return true;}
            if(x1){a[i]=x2/x1;if(fun(n-1))return true;}
            a[i]=x1;
            a[j]=x2;
        }
    }
    return false;
}

int main()
{

    int T;
    cin>>T;
    while(T--){
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        if(fun(4))cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
