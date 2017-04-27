#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a[103],sum ,ma;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        sum = 0;ma = 0;
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
            sum += a[i];
            ma = max(a[i],ma);
        }
        int ans;
        if(sum > 25) printf("0 ");
        else {
            ans = 50/ma + 1;
            printf("%d ",ans);
        }
        if(sum > 30) printf("0 ");
        else {
            ans = 60/ma + 1;
            printf("%d ",ans);
        }
        if(sum > 35) printf("0");
        else {
            ans = 70/ma + 1;
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}
