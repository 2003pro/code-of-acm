#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
bool solve(string s){
    int st = 0,ed = 0;
    int i = 0;for(;s[i]!=' ';++i);
    for(++i;s[i]!=' ';++i) st = st*10 + (s[i]-'0');
    for(++i;s[i]>='0'&&s[i]<='9';++i) ed = ed*10 + (s[i]-'0');
    if(st >= 2400 && (ed - st) > 0) return true;
    else return false;
}
char tmp[310];
string runstatus[2010];
int main()
{
    int T;scanf("%d",&T);
    fgets(tmp,300,stdin);
    for(int i = 0;i < T;i++){
        fgets(tmp,300,stdin);
        runstatus[i] = tmp;
    }
    for(int i = 0;i < T;i++){
        if(solve(runstatus[i])) {printf("YES\n");return 0;}
    }
    printf("NO\n");
    return 0;
}
