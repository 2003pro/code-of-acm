#include <bits/stdc++.h>
using namespace std;
struct pdi{
    double first,bd;int second;
    bool operator < (const pdi a) const {
        if(first != a.first)return first > a.first;
        else return bd > a.bd;
    }
};
int n;
long long a[103],ux,uy,vb,vs;
priority_queue<pdi> p;
int main()
{
    scanf("%d %I64d %I64d",&n,&vb,&vs);
    memset(a,0,sizeof(a));
    for(int i = 0;i < n;i++)scanf("%I64d",&a[i]);
    scanf("%I64d %I64d",&ux,&uy);
    for(int i = 1;i < n;i++){
        double ds = sqrt((ux - a[i])*(ux - a[i]) + (uy*uy));
        double t = ds/vs + 1.0*a[i]/vb;
        pdi tt;tt.first = t,tt.second = i+1;tt.bd = ds;
        p.push(tt);
    }
    pdi ans = p.top();
    printf("%d\n",ans.second);
    return 0;
}
