#include <bits/stdc++.h>

using namespace std;
map<string,int> mp;
int main()
{
    int n,m,a = 0;string s;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        cin>>s;
        mp[s]++;
    }
    for(int i = 0;i < m;i++){
        cin>>s;
        if(mp[s])a++;
    }
    n -= a; m -= a;
    if(a&1) n++;
    if(n - m > 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
