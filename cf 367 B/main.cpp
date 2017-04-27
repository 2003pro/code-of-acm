#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main()
{
    int n,q,t;scanf("%d",&n);
    for(int i = 0;i < n;i++) {scanf("%d",&t);v.push_back(t);}
    sort(v.begin(),v.end());
    scanf("%d",&q);
    for(int i = 0;i < q;i++){
        scanf("%d",&t);
        vector<int>::iterator l = upper_bound(v.begin(),v.end(),t);
        cout<<(l - v.begin())<<endl;
    }
    return 0;
}
