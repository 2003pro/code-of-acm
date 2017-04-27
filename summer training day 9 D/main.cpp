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
int n,a[16];
struct tia{
    int s1,s2,s3;
};
vector<tia> v;
int s[16],l,ans = 0;
bool istria(int x,int y,int z){
    bool ff = true;
    if(x+y <= z || x+z <= y || y+z <= x) ff = false;
    if(abs(x-y) >= z || abs(z-y) >= x || abs(x-z) >= y) ff = false;
    return ff;
}
bool issame(struct tia x,struct tia y){
    bool ff = true;
    if(x.s1 != y.s1 && x.s2 != y.s2 && x.s3 != y.s3) ff = false;
    return ff;
}
void dfs(int i,int cnt){
    if(i == l){ ans = max(ans,cnt);return;}
    struct tia tt = v[i];
    if(!s[tt.s1] && !s[tt.s2] && !s[tt.s3]){
        s[tt.s1] = 1,s[tt.s2] = 1,s[tt.s3] = 1;
        dfs(i+1,cnt+1);
        s[tt.s1] = 0,s[tt.s2] = 0,s[tt.s3] = 0;
        dfs(i+1,cnt);
    }
    else dfs(i+1,cnt);
}
int main()
{
    ini(s,0);
    scanf("%d",&n);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    int sum = 0;
    if(n < 3) {printf("0\n");return 0;}
    if(n == 3){
        if(istria(a[0],a[1],a[2])) printf("1\n");
        else printf("0\n");
        return 0;
    }
    for(int i = 0;i < n-2;i++){
        for(int j = i+1;j < n-1;j++){
            for(int k = j+1;k < n;k++){
                if(istria(a[i],a[j],a[k]) ){
                  struct tia tt;
                  tt.s1 = i;
                  tt.s2 = j;
                  tt.s3 = k;
                  v.push_back(tt);
                }
            }
        }
    }
    l = v.size();
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}
