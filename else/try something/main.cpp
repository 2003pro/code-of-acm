#include<bits/stdc++.h>
#define in freopen("out.txt","r",stdin)
using namespace std;
const int maxn = 3e6+7;
string s1,s2;
string ans;
int a[maxn],b[maxn];
int c[maxn];
int main(){
    in;
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s1.size();i++)
        a[i]=s1[i]-'0';
    for(int i=0;i<s2.size();i++)
        b[i]=s2[i]-'0';
    for(int i=0;i<maxn;i++){
        c[i]=c[i]+a[i]+b[i];
        while(c[i]>=2){
            c[i]-=2;
            c[i+2]++;
            c[i+3]++;
        }
    }
    int flag = 0;
    for(int i=maxn-1;i>=0;i--){
        if(c[i])flag = 1;
        if(flag)cout<<c[i];
    }
    if(flag==0)cout<<"0";
    cout<<endl;
}
