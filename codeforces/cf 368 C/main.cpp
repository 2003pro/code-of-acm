#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c;
    scanf("%I64d",&c);
    if(c == 1 || c == 2)printf("-1\n");
    else if(c%2 == 1){
        a = (c*c)/2,b = (c*c)/2 + 1;
        printf("%I64d %I64d\n",a,b);
    }
    else if(c%2 == 0){
        c /= 2;
        a = c*c - 1,b = c*c + 1;
        printf("%I64d %I64d\n",a,b);
    }
    return 0;
}
