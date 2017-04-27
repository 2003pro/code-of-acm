#include <bits/stdc++.h>

using namespace std;
char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
map<char,int> mp;
vector<string> s;
string ss;
string divhex(string t){
    string ans;
    int a1 = mp[t[0]],a2 = mp[t[1]];
    while(a1 > 0){
        ans += ('0' + a1%2)
    }
}
int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < 16;i++){
        mp[char[i]] = i;
    }
    for(int i = 0;i < n;i++){
        cin>>ss;
        s.push_back(divhex(ss));
    }
    return 0;
}
