#include <bits/stdc++.h>

using namespace std;
vector<int> ss;
int main()
{
    string t;cin>>t;
    t = 'A' + t + 'A';
    int l = t.size(),ans = 0;
    for(int i = 0;i < l;i++){
        if(t[i] - 'A' == 0 || t[i] - 'A' == 4 || t[i] - 'A' == 8 || t[i] - 'A' == 14 || t[i] - 'A' == 20 || t[i] - 'A' == 24) ss.push_back(i);
    }
    int tt = ss[0];
    for(int i = 0;i < ss.size();i++){
        if(ss[i] - tt > ans) ans = ss[i]-tt;
        tt = ss[i];
    }
    printf("%d\n",ans);
    return 0;
}
