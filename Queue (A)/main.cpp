#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

bool f = true;

int main()
{
    int c,n,b[6],cnt[6],v = 0,now;
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    int val[] = {0,1,5,10,20,50};
    for(int j = 0;j < n;j++){
        v = 0;
        scanf("%d",&c);
        for(int i=1;i<=5;i++) {
            scanf("%d",&b[i]);
            cnt[i] += b[i];
            v += b[i]*val[i];
        }
        if(!f) continue;
        now = v - c;
        for(int i=5;i>=1;i--){
            if(now >= val[i]){
                if(now/val[i] > cnt[i]){
                    now -= cnt[i]*val[i];
                    cnt[i] = 0;
                }
                else {
                    cnt[i] -= (now/val[i]);
                    now -= (now/val[i])*val[i];
                }
            }
        }
        if(now) f = false;
    }
    if(f) printf("yes\n");
    else printf("no\n");
    return 0;
}
