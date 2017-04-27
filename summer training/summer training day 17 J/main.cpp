#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
map<string,int> vis;
struct node{
    int a,b;
    string tt;
}ss[8];
bool cmp(struct node x,struct node y){
    if(x.b != y.b) return x.b > y.b;
    else return x.a < y.a;
}
int main()
{
    string s,t;int d,k = 1,T = 6;
    while(T--){
      cin>>s>>t>>d;
      if(vis[t] == 0){
        ss[k].a = d;
        ss[k].b = 1;
        ss[k].tt = t;
        vis[t] = k;
        k++;
      }
      else{
        ss[vis[t]].a = min(ss[vis[t]].a,d);ss[vis[t]].b++;
      }
    }
    sort(ss+1,ss+k,cmp);
    cout<<ss[1].tt<<endl;
    return 0;
}
