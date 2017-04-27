#include <bits/stdc++.h>
#define in freopen("jumping.in","r",stdin)
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;
template <typename T>
inline bool scan_d (T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c < '0' || c > '9') ) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template<typename T>
void print(T x) {
    static char s[33], *s1; s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) putchar('-'), x = -x;
    while(x) *s1++ = (x % 10 + '0'), x /= 10;
    while(s1-- != s) putchar(*s1);
}
template<typename T>
void println(T x) {
    print(x); putchar('\n');
}
const int N = 1e5+3;
int fa[N];
int findfa(int x){return fa[x] == x?x:fa[x] = findfa(fa[x]);}
void comb(int x,int y){int fx = findfa(x),fy = findfa(y);if(fx != fy)fa[fx] = fy;}
int a[N],ans[N];
int main()
{
    in;
    int T;int n;scan_d(T);
    while(T--){
        ini(a,0);ini(ans,0);
        scan_d(n);
        for(int i = 1;i <= n;i++) {scan_d(a[i]);fa[i] = i;}
        for(int i = 0;i <= n;i++){
            if(i+a[i] <= n)comb(i,i+a[i]);
            if(i-a[i] > 0) comb(i,i-a[i]);
        }
        int fn = findfa(n);

        for(int i = 1;i <= n;i++) println(ans[i]);
    }
    return 0;
}
