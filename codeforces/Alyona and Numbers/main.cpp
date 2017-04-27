#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    long long n,m;
    scanf("%I64d%I64d",&m,&n);
    if(n > m) {int t = n; n = m; m = t;}
    long long a[5][5];
    for(int i = 0;i < 5;i++){
        a[0][i] = 0;a[i][0] = 0;
    }
    a[1][1] = 0;a[1][2] = 0,a[1][3] = 0,a[1][4] = 1;
    a[2][1] = 0;a[2][2] = 0;a[2][3] = 1;a[2][4] = 2;
    a[3][1] = 0;a[3][2] = 1;a[3][3] = 2;a[3][4] = 3;
    a[4][1] = 1;a[4][2] = 2;a[4][3] = 3;a[4][4] = 4;
    long long ans = n*(m / 5) + (m % 5)*(n / 5) + a[n%5][m%5];
    printf("%I64d\n",ans);
    return 0;
}
