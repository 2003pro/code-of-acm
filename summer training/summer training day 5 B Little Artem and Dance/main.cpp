#include <bits/stdc++.h>

using namespace std;
int n,q,x,y,a = 1,b = 2,s[2000009];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i = 0;i < q;i++){
        scanf("%d",&x);
        if(x == 1) {
            scanf("%d",&y);
            a += y,b += y;
            a %= n,b %= n;
        }else {
            int t = a;a = b;b = t;
        }
    }
    for(int i = 0;i < n/2;i++){
        int pos1 = (a + i*2) % n;int pos2 = (b + i*2) % n;
        if(pos1 == 0) s[n] = 2*i+1;
        else if(pos2 == 0) s[n] = 2*i+2;
        s[pos1] = 2*i+1;s[pos2] = 2*i + 2;
    }
    for(int i = 1;i <= n;i++)printf("%d ",s[i]);printf("\n");
    return 0;
}
