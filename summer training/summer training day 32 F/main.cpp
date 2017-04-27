#include <bits/stdc++.h>

using namespace std;
int k;
char s[10],t[10],re[10];
vector<string> v;
int main()
{
    freopen("fraud.in","r",stdin);
    freopen("fraud.out","w",stdout);
    scanf("%s%d",s,&k);
    int l = 9,ann = 0,ans = 0;
    for(int i = 0;i < l;i++){re[i] = '!';}
    for(int i = 0;i < l;i++){
        if(s[i] != '*'){
            char tt = s[i];
            re[i] = tt;ann++;
        }
    }
    for(int i = 0;i < k;i++){
        scanf("%s",t);int ct = 0;
        for(int i = 0;i < l;i++){
            if(re[i] != '!'&&re[i] == t[i]) ct++;
        }
        if(ann == ct){
            string anss;ans++;
            for(int i = 0;i < l;i++)anss += t[i];
            v.push_back(anss);
        }
    }
    printf("%d\n",ans);
    l = v.size();
    for(int i = 0;i < l;i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
