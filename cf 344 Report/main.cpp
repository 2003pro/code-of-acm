#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N = 200003;
int a[N],r[N],t[N],b[N];
int main()
{
    int n,m,t1,r1,s = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    for(int i = 0;i < m;i++){
        scanf("%d %d",&t1,&r1);
        while(s>0&&r[s-1]<=r1)s--;
        r[s] = r1,t[s] = t1;s++;
    }
    int bl = 0,br = r[0];r[s] = 0;s++;
    for(int i = bl;i < br;i++) b[i] = a[i];
    sort(b,b+br);
    for(int i = 1;i <= s;i++){
        for(int j = r[i-1];j > r[i] ;j--){
            a[j-1] = (t[i-1] == 1)?b[--br]:b[bl++];
        }
    }
    for(int i = 0;i < n;i++) printf("%d ",a[i]);printf("\n");
    return 0;
}
