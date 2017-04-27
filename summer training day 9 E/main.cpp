#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
ll s[101][101];int n;
int main()
{
    ll sum = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            scanf("%I64d",&s[i][j]);
            sum += s[i][j];
        }
    sum /= n-1;
    for(int i = 1;i <= n;i++){
        ll t = 0,su = 0;
        for(int j = 1;j <= n;j++){
            if(s[i][j] == 0) t = j;
            su += s[i][j];
        }
        s[i][t] = sum - su;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(j < n)printf("%I64d ",s[i][j]);
            else if(j == n) printf("%I64d\n",s[i][j]);
        }
    }
    return 0;
}
