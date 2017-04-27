#include <bits/stdc++.h>

using namespace std;
int a[600],b[600];
int main()
{
    int n,k,an = 0;scanf("%d %d",&n,&k);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    if(n == 1){
        printf("%d\n",0);
        printf("%d\n",a[0]);
        return 0;
    }
    b[0] = a[0];
    for(int i = 1;i < n;i++){
        if(a[i] + b[i-1] >= k) b[i] = a[i];
        else {
            b[i] = k - b[i-1];
            an += k - a[i] - b[i-1];
        }
    }
    printf("%d\n",an);
    for(int i = 0;i < n;i++) printf("%d ",b[i]);
    printf("\n");
    return 0;
}
