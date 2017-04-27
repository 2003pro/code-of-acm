#include <bits/stdc++.h>

using namespace std;
string s,t,s1;
int a[11];
int main()
{
    cin>>s;
    cin>>t;
    int l = s.size();
    for(int i = 0;i < l;i++){
        a[i] = s[i] - '0';
    }
    sort(a,a+l);
    if(a[0] != 0){
        for(int i = 0;i < l;i++){
            char c = '0' + a[i];
            s1 += c;
        }
    }
    else {
        int t = 0,t1 = 0;
        for(int i = 1;i < l;i++){
            if(a[i] != 0){t = a[i],t1 = i;break;}
        }
        a[0] = t;a[t1] = 0;
        for(int i = 0;i < l;i++){
            char c = '0' + a[i];
            s1 += c;
        }
    }
    if(s1 == t)printf("OK\n");
    else printf("WRONG_ANSWER\n");
    return 0;
}
