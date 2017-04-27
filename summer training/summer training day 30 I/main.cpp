#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N = 100003;
struct node{
    int id,ct;
    bool operator < (const node &a) const {
        return ct < a.ct;
    }
};
int s[N],p[N],num[N],ans[N];
priority_queue<node> pp;
vector<int> rei;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n,flag = 0;struct node tt;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&s[i]);
        if(s[i] == 0){flag = 1;rei.push_back(i);}
    }
    scanf("%d",&m);
    for(int i = 1;i <= m;i++) {
        scanf("%d",&p[i]);
        if(p[i] == 0){flag = 2;rei.push_back(i);}
    }
    if(flag == 2){
        for(int i = 1;i <= n-m+1;i++){
            num[s[i]]++;tt.id = s[i],tt.ct = num[s[i]];
            pp.push(tt);
        }
        tt = pp.top();ans[1] = tt.id;
        for(int i = 2;i <= m;i++){
            num[s[i-1]]--;
            tt.ct = num[s[i-1]],tt.id = s[i-1];pp.push(tt);
            if(i+m-1 <= n){
                num[s[i+m-1]]++;
                tt.ct = num[s[i+m-1]],tt.id = s[i+m-1];pp.push(tt);
            }
            tt = pp.top();
            while(num[tt.id]!=tt.ct){
                pp.pop();tt = pp.top();
            }
            ans[i] = tt.id;
        }
        int l = rei.size();
        for(int i = 0;i < l;i++){
            p[rei[i]] = ans[rei[i]];
        }
        for(int i = 1;i < n;i++)printf("%d ",s[i]);printf("%d\n",s[n]);
        for(int i = 1;i < m;i++)printf("%d ",p[i]);printf("%d\n",p[m]);
    }
    else if(flag == 1){
        int ma = 0;
        for(int i = 1;i <= m;i++){
            num[p[i]]++;
            if(ma < p[i])ma = p[i];
        }
        int ansi = num[1];
        for(int i = 1;i <= ma;i++) if(ansi < num[i])ansi = i;
        int l = rei.size();
        for(int i = 0;i < l;i++){
            s[rei[i]] = ansi;
        }
        for(int i = 1;i < n;i++)printf("%d ",s[i]);printf("%d\n",s[n]);
        for(int i = 1;i < m;i++)printf("%d ",p[i]);printf("%d\n",p[m]);
    }
    else {
        for(int i = 1;i < n;i++)printf("%d ",s[i]);printf("%d\n",s[n]);
        for(int i = 1;i < m;i++)printf("%d ",p[i]);printf("%d\n",p[m]);
    }
    return 0;
}
