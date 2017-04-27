#include <bits/stdc++.h>

using namespace std;
char s[5003];
vector <string> re;
vector<int> a;
void solveprint(int mi,int mx){
    char te;
    for(int i = 0;i < re.size();i++){
        int le = re[i].length();

    }
}
int main()
{
    int n,mx = 0,mi = 27;scanf("%d",&n);
    scanf("%s",s);
    int l = strlen(s);
    for(int i = 0;i < l;i++){
        string tt;
        while(s[i] == '=') tt += s[i],i++;
        char ts = s[i];tt += s[i];i++;
        while((s[i] == ts || s[i] == '=')&&i < l) tt += s[i],i++;
        i--;
        if(ts == '>') a.push_back(1);
        else a.push_back(0);
        re.push_back(tt);
    }
    for(int i = 0;i < re.size();i++){
        int len = re[i].length();
        int t = 1,minx = 1,maxx = 1;
        for(int j = 0;j < len;j++){
            if(re[i][j] == '<')t++,maxx = max(maxx,t);
            else if(re[i][j] == '>')t--,minx = min(minx,t);
        }
        mx = max(maxx,mx),mi = min(minx,mi);
    }
    if((mx - mi) >= n) printf("-1\n");
    else {
        solveprint(mi,mx);
        printf("\n");
    }
    return 0;
}
