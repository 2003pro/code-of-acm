#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
const int N = 10000003;
bool isnotPrime[N];
int cnt = 0;
long long sum = 1;
long long p[N],ans[N],pre[N],times[N];

long long calc(long long x,long long y){
    long long l = y,cn = 10;
    if(y == 1) return x;
    else {
        while(l >= 10){
            l /= 10;
            cn *= 10;
        }
        return x*cn + y;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 2;i <= n ; ++i){
        if(!isnotPrime[i])
            p[cnt++] = i,ans[i] = 1,pre[i] = i,times[i] = 1;
        for(int j = 0;j < cnt &&i * p[j] <= n;++j){
            isnotPrime[i * p[j]] = true;
            pre[i * p[j]] = p[j];
            if(i % p[j] != 0){
                ans[i * p[j]] = ans[i] * calc(pre[i],times[i]);
                times[i * p[j]] = 1;
            }
            else{
                ans[i * p[j]] =ans[i];
                times[i * p[j]] = times[i] + 1;
                break;
            }
        }
        sum += ans[i] * calc(pre[i],times[i]);
    }
    printf("%lld\n",sum);
    return 0;
}
