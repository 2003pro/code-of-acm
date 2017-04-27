#include <bits/stdc++.h>

using namespace std;
typedef pair<int ,int> pii;
int n;
vector<pii> v;
vector<pii> vi;
bool cmp(pii a,pii b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
}
int main()
{
    int cnt = 1;
    while(scanf("%d",&n) != EOF && n){
        v.clear();vi.clear();
        map<pii,int> mp;
        map<pii,int> mp1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            int x,y;scanf("%d %d",&x,&y);
            pii pt;pt.first = x,pt.second = y;
            mp[pt] ++;
            if(mp[pt] == 1) v.push_back(pt);
        }
        sort(v.begin(),v.end(),cmp);
        int l = v.size();
        for(int i = 0;i < l-1;i++){
            int t = v[i].first;
            for(int j = i+1;j < l;j++){
                if(v[i].second > v[j].second) {v[i].first = v[j].second;break;}
            }
            pii pt,pt1;pt.first = v[i].first,pt.second = v[i].second;pt1.first = t,pt1.second = v[i].second;
            if(pt != pt1) mp[pt] = mp[pt1];
        }
        sort(v.begin(),v.end(),cmp);
        for(int i = 0;i < l;i++){
            pii pt;pt = v[i];
            mp1[pt] ++;
            if(mp1[pt] == 1) vi.push_back(pt);
            else mp[pt]++;
        }
        l = vi.size();
//        for(int i = 0;i < l;i++)printf("%d %d %d\n",vi[i].first,vi[i].second,mp[vi[i]]);
        for(int i = 0;i < l;i++){
            int ll = (vi[i].second - vi[i].first)*2;
            if(ll > mp[vi[i]]) sum += mp[vi[i]];
            else sum += ll;
        }
        printf("On day %d Emma can attend as many as %d parties.\n",cnt,sum);
        cnt++;
    }
    return 0;
}
