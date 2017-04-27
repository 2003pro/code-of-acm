#include <bits/stdc++.h>

using namespace std;
int a[2003],n,d,sum = 0;
int main()
{
    scanf("%d %d",&n,&d);
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i < n-1;i++){
        if(a[i]-a[i+1] >= 0){
            sum += (a[i]-a[i+1])/d + 1;
            a[i+1] += ((a[i]-a[i+1])/d + 1)*d;
        }
    }
    printf("%d\n",sum);
    return 0;
}
