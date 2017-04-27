#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int ss[29],k,ans = 0,tot,lagsize;
map<char,int> vis;
string s;
bool cmp(int a,int b){
    return a > b;
}
void dfs(int x,int sum,int totax){
    if(x <= k+1 && sum == lagsize && totax == tot){ans++;return;}
    if(x > k || totax >= tot) return ;
    dfs(x + 1,sum,totax);
    dfs(x + 1,sum + ss[x],totax+1);
    return ;
}
int main()
{
    ini(ss,0);
    cin>>s>>k;tot = k;
    int l = s.size(),cnt = 1;
    for(int i = 0;i < l;i++){
        char tt = s[i];
        if(vis[tt] == 0){
            vis[tt] = cnt;ss[cnt]++;cnt++;
        }
        else {
            ss[vis[tt]]++;
        }
    }
    sort(ss+1,ss+cnt,cmp);
    lagsize = 0;
    for(int i = 1;i <= k;i++) lagsize += ss[i];
    while(ss[k+1] == ss[k]&&k < cnt-1) k++;
    dfs(1,0,0);
    printf("%d %d\n",lagsize,ans);
    return 0;
}
