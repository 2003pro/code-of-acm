#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#define iOS ios_base::sync_with_stdio(false)
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int INF = 99999;
int n,m,w,d[503],cnt;
struct edge{
    int st,ed,wei;
} s[5203];

bool bellmanford(){
    int a,b,c,i,k;
    for(i = 2;i <= n;i++)d[i] = INF;
    for(k = 0;k < n-1;k++){
        bool flag = true;
        for( i = 0;i < cnt;i++){
            a = s[i].st,b = s[i].ed,c = s[i].wei;
            if(d[b] > d[a]+c) {d[b] = d[a] + c;flag = false;}
        }
        if(flag) break;
    }
    for(i = 0;i < cnt;i++){
        a = s[i].st,b = s[i].ed,c = s[i].wei;
        if(d[b] > d[a]+c) return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        ini(d,0);
        int x,y,wi;
        scanf("%d%d%d",&n,&m,&w);
        cnt = 0;
        for(int i = 0;i < m;i++){
            scanf("%d%d%d",&x,&y,&wi);
            s[cnt].st = x,s[cnt].ed = y,s[cnt].wei = wi;cnt++;
            s[cnt].st = y,s[cnt].ed = x,s[cnt].wei = wi;cnt++;
        }
        for(int j = 0;j < w;j++){
            scanf("%d%d%d",&x,&y,&wi);
            s[cnt].st = x,s[cnt].ed = y,s[cnt].wei = -wi;cnt++;
        }
        if(bellmanford()) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
