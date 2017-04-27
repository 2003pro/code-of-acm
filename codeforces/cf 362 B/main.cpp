#include <bits/stdc++.h>

using namespace std;
string s;
int a = 0,b = 0,d = 0;
vector<char> v;
int main()
{
    cin>>s;
    int e = s.find('e');
    if(s[0] == '0') {
        for(int i = 0;i < e;i++) 	v.push_back(s[i]);
        while(v.back() == '0') v.pop_back();
        if(v.back() == '.') v.pop_back();
    }
    else {
        v.push_back(s[0]);int l = s.size();int cn = 0;
        for(int i = e+1;i < l;i++) cn = cn*10 + s[i] - '0';
        for(int i = 2;i < e;i++) {
            if(cn == 0) v.push_back('.');
            v.push_back(s[i]);cn--;
        }
        if(cn < 0){while(v.back() == '0') v.pop_back();}
        while(cn > 0) {v.push_back('0');cn--;}
        if(v.back() == '.') v.pop_back();
    }
    int vl = v.size();
    for(int i = 0;i < vl;i++) printf("%c",v[i]);
    return 0;
}
