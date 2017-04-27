#include <bits/stdc++.h>

using namespace std;
string s,s1;
vector<char> ans;
int main()
{
    int n,t;char t1;
    scanf("%d %d",&n,&t);
    cin>>s;
    int st = s.find('.');
    for(int i = 0;i < st;i++) s1 += s[i];
    st++;
    while(s[st] - '0' < 5 && st < n){
        ans.push_back(s[st++]);
    }
    if(st < n) ans.push_back(s[st]);
    t1 = ans.back();
    while(t-- > 0 && ans.size() > 1 && t1 > '4'){
        ans.pop_back();
        t1 = ans.back();
        t1++;
        ans.pop_back();
        ans.push_back(t1);
    }
    t++;
    if(ans.size() > 1){
        s1 += '.';
        for(int i = 0;i < ans.size();i++) s1 += ans[i];
        cout<<s1<<endl;
    }
    if(ans.size() == 1){
        if(t1 > '4' && t > 0){
            st = s.find('.');
            if(s1[st-1] < '9')s1[st-1] = (s1[st-1]+1);
            else {s1[st-1] = '0';s1[st-2] = (s1[st-2]+1);}
            cout<<s1<<endl;
        }
        else {
            s1 += '.';
            for(int i = 0;i < ans.size();i++) s1 += ans[i];
            cout<<s1<<endl;
        }
    }
    return 0;
}
