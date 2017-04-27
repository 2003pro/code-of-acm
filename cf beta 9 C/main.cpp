#include <bits/stdc++.h>

using namespace std;
int jud[1024],n;
int main()
{
    for(int i = 1;i <= 1023;i++){
        int s = 0,bas = 1,t = i;
        while(t){
            s += (t%2)*bas;
            bas *= 10;
            t /= 2;
        }
        jud[i] = s;
    }
    scanf("%d",&n);
    for(int i = 1;i <=1023;i++){
        if(n < jud[i]) {printf("%d\n",i-1);break;}
    }
    return 0;
}
