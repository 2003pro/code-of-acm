#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;

int main()
{
    long long t,n;
    while(cin>>n){
        double sum = 0;
        for(int i = 0;i < n;i++) {
            scanf("%lld",&t);
            sum += sqrt(t);
        }
        long long l = sum;
        double r = sum - l;
        if(r == 0.0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
