#include <bits/stdc++.h>

using namespace std;
int gcd(int x,int y){return y == 0? x : gcd(y,x%y);}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s = 6 - max(m,n) + 1;
    int pu = gcd(s,6);
    printf("%d/%d\n",s/pu,6/pu);
    return 0;
}
