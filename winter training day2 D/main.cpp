#include <bits/stdc++.h>

using namespace std;
const int N = 100003;
typedef pair<int,int> pii;
priority_queue <int,vector<int>,greater<int> > q;
pii aa[N];
bool cmp(const pii x,const pii y){
    if(x.first != y.first) return x.first > y.first;
    else return x.second > y.second;
}
int main()
{
    int n;scanf("%d",&n);
    int cn = n;int t;
    for(int i = 0;i < n;i++){
        scanf("%d",&t);
        aa[i].first = t;
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&t);
        aa[i].second = t;
    }
    sort(aa,aa+n,cmp);
    //    for(int i = 0;i < n;i++) printf("%d %d\n",aa[i].first,aa[i].second);
    for(int i = 1;i < n;i+=2){
        q.push(aa[i].second);q.push(aa[i+1].second);
        q.pop();
    }
    long long ans = 0;
    while(!q.empty()){
        ans += q.top();
        q.pop();
    }
    printf("%I64d\n",ans);
    return 0;
}
