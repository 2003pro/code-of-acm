#include <bits/stdc++.h>

using namespace std;
struct edge {
    int from,to,weight;
};
struct edge ee[100003];
int mp[100003];
priority_queue<int,vector<int>,greater<int> > p;
int main()
{
    int n,m,k,t,a,b,c;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        ee[i].from = a,ee[i].to = b,ee[i].weight = c;
    }
    for(int i = 0;i < k;i++) {scanf("%d",&t);mp[t] = 1;}
    if(k > 0){
        for(int i = 0;i < m;i++){
            if(!mp[ee[i].from]&&mp[ee[i].to]) p.push(ee[i].weight);
            if(mp[ee[i].from]&&!mp[ee[i].to]) p.push(ee[i].weight);
        }
        if(p.empty()) printf("-1\n");
        else {
            int ans = p.top();
            printf("%d\n",ans);
        }
    }
    else printf("-1\n");
    return 0;
}
