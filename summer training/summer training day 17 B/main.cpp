#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int ss[10003];
int main()
{
    int T;scanf("%d",&T);ini(ss,0);
    while(T--){
        int a,b;
        scanf("%d %d",&a,&b);
        int n = a/b,sum = 0,sum1 = 0;
        if(a%b == 0){
            while(a > 0){
                sum += (a - n)*n;a -= n;
            }
        }
        else {
            for(int i = 1;i <= b;i++) ss[i] = n;
            int t = a%b;
            for(int i = 1;i <= t;i++) ss[i]++;
            for(int i = 1;i < b;i++) {sum += (a-ss[i])*ss[i];a -= ss[i];}
        }
        printf("%d\n",sum);
    }
    return 0;
}
