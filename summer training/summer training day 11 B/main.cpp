#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int a[10003],n,mp[10003];
int main()
{
    int T;
    scanf("%d",&T);
    for(int k = 1;k <= T;k++){
        ini(mp,0);
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        bool flag = true;
        if(n%2 == 0){
            for(int i = 1;i <= n;i++){
                if(a[i] >= 0 && a[i] < n) mp[a[i]]++,mp[n-a[i]-1]++;
                if(mp[a[i]] > 2) {flag = false;break;}
                if(a[i] > n-1) {flag = false;break;}
            }
        }
        else {
            for(int i = 1;i <= n;i++){
                if(a[i] >= 0 && a[i] < n && a[i] != n/2) mp[a[i]]++,mp[n-a[i]-1]++;
                else if(a[i] == n/2) mp[a[i]]++;
                if(mp[a[i]] > 2 && a[i] != n/2) {flag = false;break;}
                if(a[i] > n-1) {flag = false;break;}
                if(mp[n/2] > 1){flag = false;break;}
            }
        }
        printf("Case %d: ",k);
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
