#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
typedef long long ll;
using namespace std;
ll r[100002],c[100002],ru,cu,n,m,s[100002];
ll sum = 0;
int main()
{
    ini(r,0);ini(c,0);ini(s,0);
    scanf("%I64d %I64d",&n,&m);
    sum = n*n;ru = 0,cu = 0;
    for(int i = 0;i < m;i++){
        ll x,y;
        scanf("%I64d %I64d",&x,&y);
        if(r[x] == 0 && c[y] == 0){
            sum = sum - (n-ru) - (n-cu) + 1;
            r[x] = 1,c[y] = 1;ru++,cu++;
        }
        else if(r[x] == 1 && c[y] == 0){
            sum -= (n-ru);cu++;
            r[x] = 1,c[y] = 1;
        }
        else if(r[x] == 0 && c[y] == 1){
            sum -= (n-cu);ru++;
            r[x] = 1,c[y] = 1;
        }
        s[i] = sum;
    }
    for(int i = 0;i < m;i++) printf("%I64d ",s[i]);printf("\n");
    return 0;
}
