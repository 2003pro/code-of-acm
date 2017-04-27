#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#define iOS ios_base::sync_with_stdio(false)
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)
using namespace std;
map<string,int> s;
map<string,vector<string> > sclass;
vector<string> cp;
vector<char> v;
int n;
string s1,t,c;
vector<long long> comp;

int main()
{
    iOS;
    string dem = "bmail.com";cp.push_back("ss");comp.push_back(0);
    s1 = ' ';int sum = 0;
    cin>>n;int k = 0;
    for(int i = 0;i < n;i++){
        cin>>s1;c = tolower(s1[0]);
        int e = s1.find('@'); t = tolower(s1[e+1]);
        for(int i = e+2;i < s1.size();i++){
            if(s1[i] >= 'A' && s1[i] <= 'Z') t += tolower(s1[i]);
            else t += s1[i];
        }
        bool cc = false;
        if(t == dem) cc = true;
        string::size_type l = s1.find('+');
        if( l != string::npos && cc) e = s1.find('+');
        if(cc){
            for(int i = 1;i < e;i++){
                if(s1[i] >= 'A' && s1[i] <= 'Z') c += tolower(s1[i]);
                else if(s1[i] != '.') c += s1[i];
            }
        }
        else{
            for(int i = 1;i < e;i++){
                if(s1[i] >= 'A' && s1[i] <= 'Z') c += tolower(s1[i]);
                else  c += s1[i];
            }
        }
        c += t;
        sclass[c].push_back(s1);
        s[c]++;
        if(s[c] == 1) {k++;cp.push_back(c);}
//        long long c1 = hashStr(c);
//        if(find(comp.begin(),comp.end(),c1)==comp.end()) {comp.push_back(c1);k++;sclass[c] = k;}
//        int tt = sclass[c];
//        s[tt].push_back(s1);
    }
    cout<<k<<endl;
    for(int i = 1;i < cp.size();i++){
        cout<<sclass[cp[i]].size()<<' ';
        for(int j = 0;j < sclass[cp[i]].size();j++) cout<<sclass[cp[i]][j]<<' ';
        cout<<endl;
    }
    return 0;
}
