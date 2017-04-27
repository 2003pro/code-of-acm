#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <queue>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
char s[21];int n,l;
char mod[103][6];
int vis[103];
string ss = "";
bool flag = false;
vector<vector<int> > g;
void dfs(int k,){
    if(k == l){return ;}
    int le = g[k].size();
    if(le == 0) flag = false;return ;
    for(int i = 0;i < le;i++){
        if(!vis[g[k][i]])
    }
}
int main()
{
    ini(vis,0);
    scanf("%s",s);scanf("%d",&n);
    for(int i = 0;i < n;i++){
        char c;int k = 0;
        for(int i = 0;i < 6;i++){
            scanf("%c",&c);
            if(isalpha(c)) {mod[i][k] = c;k++;}
        }
    }
    l = strlen(s);
    for(int i = 0;i < l;i++){
        for(int j = 0;j < n;j++){
            int l1 = strlen(mod[j]);
            for(int k = 0;k < l1;k++) if(mod[j][k] == s[i]) g[i].push_back(j);
        }
    }
    dfs(0);
    return 0;
}
