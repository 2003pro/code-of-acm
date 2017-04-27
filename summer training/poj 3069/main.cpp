#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ini(x,y) memset(x,y,sizeof(x));
using namespace std;
const int N = 1003;
int x[N],n,r;
int main()
{
    while(scanf("%d%d",&r,&n) && r != -1 && n != -1){
        for(int i = 0;i < n;i++) scanf("%d",&x[i]);
        sort(x,x+n);
        int i = 0,ans = 0;
        while(i < n){
            int s = x[i++];
            while(i < n && x[i] <= s+r)i++;
            int p = x[i-1];
            while(i < n && x[i] <= p+r)i++;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
