#include <iostream>
#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 60;
ll c[N][N];

void makec(){
    for(int i = 0;i < N;i++) c[i][0] = 1;
    for(int i = 1;i < N;i++){
        for(int j = 1;j <= std::min(i,N - 1);j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

ll solve(ll x){
    ll n = x/3,sum = 0;
    if(x%2 == 0){
        for(ll i = 0;i <= n;i += 2) sum += c[(x + i)/2][i] * c[(x + i)/2][i];
    }
    else {
        for(ll i = 1;i <= n;i += 2) sum += c[(x + i)/2][i] * c[(x + i)/2][i];
    }
    return sum;
}

int main()
{
    makec();
    int T; ll a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&a,&b);
        printf("%lld %lld\n",a,solve(b/2));
    }
    return 0;
}
