#include <bits/stdc++.h>

using namespace std;
string ss[53];
map<string ,int> mp;
int main()
{
    string s,t;
    cin>>s;
    ss[0] = s;
    int cnt = 1;
    mp[s]++;
    int n = s.length();
    for(int i = 1;i < n;i++){
        t = ss[i-1];
        t.erase(0,1);
        t += ss[i-1][0];
        ss[i] = t;
        if(mp[t] == 0) cnt++,mp[t]++;
    }
    cout<<cnt<<endl;
    return 0;
}
