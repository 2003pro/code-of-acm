#include <bits/stdc++.h>

using namespace std;
const int N = 300003;
typedef pair<double,double> pdd;
double c[N],x[N];
pdd p[N];
vector<pdd> v;
map<pdd,int> mp;
int lfind(int n,double x){
    int lb = 0,ub = n;
    while(ub - lb > 1){
        int mid = (lb + ub)/2;
        if(c[mid] >= x) ub = mid;
        else lb = mid;
    }
    return ub;
}
int ufind(int n,double x){
    int lb = 0,ub = n;
    while(ub - lb > 1){
        int mid = (lb + ub)/2;
        if(c[mid] > x) ub = mid;
        else lb = mid;
    }
    return lb;
}
bool cmp(pdd a,pdd b){
    return a.second < b.second;
}
int main()
{
    int n,m,r;scanf("%d%d%d",&m,&n,&r);
    for(int i = 1;i <= m;i++) scanf("%lf",&c[i]);
    for(int i = 1;i <= n;i++) {
        scanf("%lf",&x[i]);
        double low = x[i] - sqrt(r*r+1),high = x[i] + sqrt(r*r+1);
        double l = lfind(m,low),r = ufind(m,high);
        p[i].first = l,p[i].second = r;mp[p[i]] = i;
    }
    sort(p+1,p+n+1,cmp);v.push_back(p[1]);double ubd = p[1].second;
    for(int i = 2;i < n;i++){
        if(p[i].first > ubd) v.push_back(p[i]),ubd = p[i].second;
    }
    int l = v.size();double t = c[1],ans = 0;
    for(int i = 0;i < l;i++){
        printf("%f\n",c[mp[v[i]]]);
        ans += abs(t - c[mp[v[i]]]);t = c[mp[v[i]]];
    }
    printf("%.1f\n",ans);
    return 0;
}
