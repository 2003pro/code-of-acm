#include <bits/stdc++.h>

using namespace std;
map<char,int> mp;
char s[103];
int main()
{
    for(int i = 0;i < 26;i++)
        mp['a'+i] = i;
    int t = 0;
    scanf("%s",s);
    int l = strlen(s),sum = 0;
    for(int i = 0;i < l;i++){
        if(abs(mp[s[i]] - t) > 13) sum += 26 - abs(mp[s[i]] - t);
        else sum += abs(mp[s[i]] - t);
        t = mp[s[i]];
    }
    printf("%d\n",sum);
    return 0;
}
