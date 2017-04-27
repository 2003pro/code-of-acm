#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
    int T;
    scanf("%d",&T);
    for(int k = 1;k <= T;k++){
        cin>>s;
        int y = 0,z = 0;
        int l = s.size();
        for(int i = 0;i < l-1;i++){
            if(s[i] == 'S' && s[i+1] == 'S') y++;
            if(s[i] == 'S' && s[i+1] != 'S') z++;
        }
        printf("Case %d: %d / %d\n",k,y,z);
    }
    return 0;
}
