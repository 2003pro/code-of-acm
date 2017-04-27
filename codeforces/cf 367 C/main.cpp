#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t[100003];
vector<string> st;
bool lcmp(string a,string b){
    if(a.length() < b.length()) return true;
    else if(a.length() == b.length()){
        int l = a.length(),fl = 0;
        for(int i = 0;i < l;i++){
            if(a[i] < b[i]) continue;
            else if(a[i] == b[i]) fl++;
            else return false;
        }
        if(fl == l)return false;
    }
    else return false;
}
int main()
{
    ll n,tl,ans = 0;scanf("%I64d",&n);string t;
    for(ll i = 0;i < n;i++) scanf("%I64d",&t[i]);
    cin>>t;st.push_back(t);tl = t.length();
    for(ll i = 1;i < n;i++){
        cin>>t;st.push_back(t);
        ll l = t.length();
        if(l < tl) {printf("-1\n");return 0;}
        else tl = l;
    }
    ll l = st.size();
    for(ll i = 1;i < l;i++){
        string s1,s2;
        if(lcmp(v[i-1],v[i])) continue;
        else {
            s1.assign(v[i-1].rbegin(),v[i-1].rend());
            s2.assign(v[i].rbegin(),v[i].rend());
            if(lcmp(s1,v[i])){ans += t[i-1];continue;}
            if(lcmp(v[i-1],s2)){ans += t[i];continue;}
            if(lcmp(s1,s2)) {ans += (t[i-1]+t[i]);}
        }
    }
    return 0;
}
