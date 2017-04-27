#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 60;
long long c[N][N];

void makec(){
    for(int i = 0;i < N;i++) c[i][0] = 1;
    for(int i = 1;i < N;i++){
        for(int j = 1;j <= min(i,N - 1);j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main()
{
    makec();
    long long n,k;
    scanf("%lld%lld",&n,&k);
    printf("%lld\n",c[n + k - 1][n - 1]);
    return 0;
}
