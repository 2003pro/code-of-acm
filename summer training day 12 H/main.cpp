#include <bits/stdc++.h>

using namespace std;
int a[100003],k,n;
bool C(int l){
    int s = a[1],t = s+l-1,cnt=1;
    for(int i = 2;i<=n;i++){
        if(a[i] <= t) continue;
        else{
            s = a[i];t = s+l-1;cnt++;
        }
    }
    if(cnt <= k)return true;
    else return false;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
        int ub = -1,lb = a[n];
        while(lb - ub > 1){
            int mid = (lb+ub)/2;
            if(C(mid)) lb = mid;
            else ub = mid;
        }
        printf("%d\n",lb);
    }
    return 0;
}
