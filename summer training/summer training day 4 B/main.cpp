#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
long long a,b;
long long solve(long long j){
    ll l = j,p=2;
    while(l>=p){
        l = l-l/p;p++;
    }
    return l;
}
int main()
{
    scanf("%I64d %I64d",&a,&b);
    long long a1 = solve(a-1),b1 = solve(b);
    printf("%I64d\n",b1-a1);
    return 0;
}
