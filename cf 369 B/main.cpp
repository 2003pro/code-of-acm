#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll grid[503][503];
int main()
{
    int n,ei,ej;scanf("%d",&n);ll t,sum,sum1;
    if(n == 1) {
        scanf("%I64d",&t);
        printf("1\n");return 0;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            scanf("%I64d",&grid[i][j]);
            if(grid[i][j] == 0) ei = i,ej = j;
        }
    }
    sum = 0;
    if(ei != n) for(int i = 1;i <= n;i++) sum += grid[ei+1][i];
    else for(int i = 1;i <= n;i++) sum += grid[ei-1][i];
    for(int i = 1;i <= n;i++){
        sum1 = 0;
        if(i != ei) {
            for(int j = 1;j <= n;j++) sum1 += grid[i][j];
            if(sum != sum1) {printf("-1\n");return 0;}
        }
        sum1 = 0;
        if(i != ej) {
            for(int j = 1;j <= n;j++) sum1 += grid[j][i];
            if(sum != sum1) {printf("-1\n");return 0;}
        }
    }
    if(ei != ej){
        sum1 = 0;
        for(int i = 1;i <= n;i++) sum1 += grid[i][i];
        if(sum != sum1) {printf("-1\n");return 0;}
    }
    if(ej != n-ei+1){
        sum1 = 0;
        for(int i = 1;i <= n;i++) sum1 += grid[i][n-i+1];
        if(sum != sum1) {printf("-1\n");return 0;}
    }
    sum1 = 0;
    for(int i = 1;i <= n;i++) sum1 += grid[ei][i];
    if(sum - sum1 > 0) {
        ll an = sum - sum1;
        if(ei == ej){
            sum1 = 0;
            for(int i = 1;i <= n;i++) sum1 += grid[i][i];
            sum1 += an;
            if(sum != sum1) {printf("-1\n");return 0;}
        }
        if(ej == n-ei+1){
            sum1 = 0;
            for(int i = 1;i <= n;i++) sum1 += grid[i][n-i+1];
            sum1 += an;
            if(sum != sum1) {printf("-1\n");return 0;}
        }
        printf("%I64d\n",an);
    }
    else printf("-1\n");
    return 0;
}
