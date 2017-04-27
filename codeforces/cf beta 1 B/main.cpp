#include <bits/stdc++.h>

using namespace std;
int n;
string tt;
void cov1(string s){
    int lc = s.find('C'),le = s.size();
    int col = 0,row = 0;
    for(int i = 1;i < lc;i++) row = row*10 + s[i] - '0';
    for(int i = lc + 1;i < le;i++) col = col*10 + s[i] - '0';
    string sc = "";
    while(col){
        int k = 0;
        k = col%26;char c;
        if(k > 0)c = 'A'+ k-1;
        else c = 'Z';
        sc += c;
        if(k)col = col/26;
        else col = col/26 - 1;
    }
    reverse(sc.begin(),sc.end());
    cout<<sc<<row<<endl;
}
void cov2(string s){
    int l = s.size();int row = 0,col = 0,c;
    for(int i = 0;i < l;i++)if(isdigit(s[i])) {c = i;break;}
    for(int i = c;i < l;i++){
        char c1 = s[i];
        int cur = c1 - '0';
        row = row*10 + cur;
    }
    for(int i = 0;i < c;i++){
        char c1 = s[i];
        int cur = c1 - 'A' + 1;
        col  = col*26 + cur;
    }
    cout<<'R'<<row<<'C'<<col<<endl;
}
int main()
{
    cin>>n;
    while(n--){
        cin>>tt;
        int l = tt.size();
        bool ff = false;
        for(int i = 0;i < l-1;i++){
            if(isdigit(tt[i]) && (tt[i+1] >= 'A' && tt[i+1] <= 'Z')) ff = true;
        }
        if(ff) cov1(tt);
        else cov2(tt);
    }
    return 0;
}
