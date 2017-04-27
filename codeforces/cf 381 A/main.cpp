#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n,s[4];
    scanf("%I64d%I64d%I64d%I64d",&n,&s[1],&s[2],&s[3]);
    ll l = 4 - n%4;
    ll a,b,c;
    if(l == 4) printf("0\n");
    else {
        if(l == 1){
            a = s[1];
            b = s[2]+s[3];
            c = s[3]*3;
            printf("%I64d\n",min(a,min(b,c)));
        }
        else if(l == 2){
            a = s[1]*2;
            b = s[2];
            c = s[3]*2;
            printf("%I64d\n",min(a,min(b,c)));
        }
        else {
            a = s[1]*3;
            b = s[2]+s[1];
            c = s[3];
            printf("%I64d\n",min(a,min(b,c)));
        }
    }
    return 0;
}
