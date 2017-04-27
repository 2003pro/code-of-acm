#include <bits/stdc++.h>
#define rep(i,j,k) for(long long i = (long long)j;i < (long long)k;i++)
using namespace std;

int main()
{
    long long s, l = 1e7;scanf("%I64d",&s);
    int cnt = 0;
    rep(i,2,min(l,s)+1){
        while(s%i == 0){
            s /= i;
            cnt++;
        }
    }
    if(cnt == 20 && s == 1) printf("Yes\n");
    else if(cnt == 19 && s != 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
