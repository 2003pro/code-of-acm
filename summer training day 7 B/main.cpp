#include <bits/stdc++.h>

typedef long long ll;
struct node{
    ll a,b;
    bool operator < (const node c) const{
        return a > c.a;
    }
}e[4003];
using namespace std;
int n;ll sum,c[4003],tmp,sx,sy;

int main()
{
    scanf("%d",&n);ll x,y;
    for(int i = 1;i <= n;i++){
        scanf("%I64d %I64d",&x,&y);
        if(x > y) e[i].a = x,e[i].b = y;
        else e[i].a = y,e[i].b = x;
    }
    sort(e+1,e+1+n);sum = 0;
    for(int i = 1;i <= n;i++){
        c[i] = e[i].b;
        sort(c,c+i);
        for(int j = i;j > 0;j--){
            tmp = 1ll*e[i].a*c[j]*(i-j+1);
            if(tmp > sum){sum = tmp;sx = e[i].a,sy = c[j];}
        }
    }
    printf("%I64d\n%I64d %I64d\n",sum,sx,sy);
    return 0;

}
