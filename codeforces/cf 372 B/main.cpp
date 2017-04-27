#include <bits/stdc++.h>

using namespace std;
string s;
int cnt[26];
char cans[50003];
int main()
{
    cin>>s;
    int ct = 0,ct1 = 0,fl = 0,fs;
    if(s.length() < 26) printf("-1\n");
    int l = s.length();
    const char *cname=s.c_str();
    strcpy(cans, cname);
    for(int j = 0;j <= l - 26;j++){
        ct = 0,ct1 = 0;memset(cnt,0,sizeof(cnt));
        for(int i = j;i < j+26;i++){
            if(s[i] - 'A' >=0 && s[i] - 'A' < 26) {
                cnt[s[i] - 'A']++;ct++;
                if(cnt[s[i] - 'A'] > 1) {ct = -1;break;}
            }
            else ct1++;
        }
        if(ct+ct1 == 26) {fs = j,fl = 1;break;}
    }
    if(fl == 0) printf("-1\n");
    else {
        for(int i = fs;i < fs+26;i++){
            if(cans[i] == '?'){
                for(int j = 0;j < 26;j++){
                    if(cnt[j] == 0) {cnt[j] = 1;cans[i] = 'A'+j;break;}
                }
            }
        }
        for(int i = 0;i < l;i++){
            if(cans[i] == '?') cans[i] = 'A';
        }
        for(int i = 0;i < l;i++) printf("%c",cans[i]);printf("\n");
    }
    return 0;
}
