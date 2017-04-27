#include <bits/stdc++.h>

using namespace std;
int n,m,a[103],b[103];
map<string,int> mp;
string st;
bool cmp(int a,int b){return a> b;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    int cnt = 0;
    for(int i = 0;i < m;i++){
        cin>>st;
        mp[st]++;
    }
    for(map<string,int>::iterator it = mp.begin();it != mp.end();++it){
        b[cnt] = (*it).second;cnt++;
    }
    sort(b,b+cnt,cmp);
    int mi = 0,mx = 0;
    for(int i = 0;i < cnt;i++) mi += a[i]*b[i];
    sort(a,a+n,cmp);
    for(int i = 0;i < cnt;i++) mx += a[i]*b[i];
    printf("%d %d\n",mi,mx);
    return 0;
}
