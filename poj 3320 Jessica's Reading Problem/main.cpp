#include <bits/stdc++.h>

using namespace std;
set<int> all;
map<int,int> mp;
int s[1000000],n;
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {scanf("%d",&s[i]);all.insert(s[i]);}
    int n1 = all.size();
    int s1 = 0,t1 = 0,ans1 = n,ans = 0;
    for(;;){
        while(t1 < n && ans < n1){
            if(mp[s[t1++]]++ == 0) ans++;
        }
        if(ans < n1) break;
        ans1 = min(ans1,t1-s1);
        if(--mp[s[s1++]] == 0) ans--;
    }
    printf("%d\n",ans1);
    return 0;
}
