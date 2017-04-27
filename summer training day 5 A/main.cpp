#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define iOS ios_base::sync_with_stdio(false)
using namespace std;
const int N = 100005;
vector<vector<int> > g(2*N);
int deep = 0,n,k1 = 1,m,low[N],high[N],tree[N];
bool pick[N];
int read(int k) {
  int sum = 0;
  for (; k; k^=k&-k) sum+=tree[k];
  return sum;
}
void update(int k, int v) {
  for (; k<=n; k+=k&-k) tree[k]+=v;
}
void dfs(int k,int fa){
    low[k] = ++deep;
    for(int i = 0;i < g[k].size();i++)if(g[k][i] != fa) dfs(g[k][i],k);
    high[k] = deep;
}
int main()
{
    iOS;
    scanf("%d",&n);int x,y;
    for(int i = 0;i < n-1;i++) {
        scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i = 1;i <= n;i++) update(i,1);
    dfs(1,0);memset(pick,1,sizeof(pick));
    scanf("%d",&m);
    while(m--){
        char s[2];int l;
        scanf("%s",s);scanf("%d",&l);
        if (s[0] == 'C') update(low[x], pick[x] ? -1 : 1), pick[x] = !pick[x];
        else printf("%d\n",read(high[l]) - read(low[l]-1));
    }
    return 0;
}
