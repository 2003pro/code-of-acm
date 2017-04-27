#include <bits/stdc++.h>

using namespace std;
typedef pair<int ,int> pii;
vector<pii> sk;
queue <string> p;
stack <char> p1;
stack <int> pp;
string tt;
char s1[1003];
int main()
{
    string s,s2;
    while(cin >> s){
        if(s[0] == '(') s = s.substr(1,s.length()-2);
        int l = s.length(),i,vis=0,flag = 0;
        strcpy(s1,s.c_str());
        for(int i = 0;i < l;i++){
            if(s1[i] != '(' && s1[i] != ')') p1.push(s1[i]);
            else {
                if(s1[i] == '(') pp.push(i);
                else {
                    pii t;t.first = pp.top();t.second = i;pp.pop();
                    sk.push_back(t);
                }
            }
        }
        for(int i = 0;i < sk.size();i++){
            if(sk[i-1].first - sk[i].first == 1 && sk[i].second - sk[i-1].second == 1){
                int t1 = sk[i].first,t2 = sk[i].second;
                s1[t1] = '0';s1[t2] = '0';
            }
//            printf("%d %d\n",sk[i].first,sk[i].second);
        }
        for(int i = 0;i < l;i++) {
            if(s1[i] != '0') s2 += s1[i];
        }
        strcpy(s1,s2.c_str());

    }
    return 0;
}
