#include <bits/stdc++.h>

using namespace std;
int n,p1,p2,p3,t1,t2,l[103],r[103];
int main()
{
    scanf("%d %d %d %d %d %d",&n,&p1,&p2,&p3,&t1,&t2);
    for(int i = 1;i <= n;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    l[0] = l[1],r[0] = l[1];
    int sum = 0;
    for(int i = 1;i <= n;i++){
        sum += (r[i] - l[i])*p1;
        int t = l[i] - r[i-1];
        if(t <= t1) sum += t*p1;
        else if(t > t1 && t <= t2) sum += p1*t1 + p2*(t-t1);
        else if(t > t2) sum += p1*t1 + p2*t2 + p3*(t-t1-t2);
    }
    printf("%d\n",sum);
    return 0;
}
