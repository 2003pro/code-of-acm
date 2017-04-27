#include <bits/stdc++.h>

using namespace std;
int a[200003];
int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    int t = 0;
    for(int i = 0;i < n;i++){
        if(a[i] >= t) a[i] -= t;
        else {
            if(a[i] >= (t%2)) a[i] -= (t%2);
            else {
                printf("NO\n");
                return 0;
            }
        }
        t = a[i];
    }
    if(t%2 == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
