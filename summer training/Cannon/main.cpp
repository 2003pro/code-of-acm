#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x));
using namespace std;
int a[26],b[26];
int n,m,l,cnt = 0,ans = 0,f[] = {1,10,100,1000,10000,100000};
int s[6][6];
int fin(int x){
    int l1[] = {212,222,1212,2121,1222,2221,2212,2122,11212,12121,21211,21212,11222,12122,22211,22121,12212,21221,12221};
    for(int i = 0;i < 19;i++){if(x == l1[i]) return 1;}
    return 0;
}
int judge(int x,int y){
    int cot1 = 0,cot2 = 0,x1 = 0,y1 = 0;
    for(int i = 0;i < n;i++){
        if(s[i][y] == 1) {x1 += 1*f[cot1];cot1++;}
        else if(s[i][y] == 2) {x1 += 2*f[cot1];cot1++;}
        else if(i == x) {x1 += 2*f[cot1];cot1++;}
    }
    if(fin(x1) == 1) return 0;
    for(int i = 0;i < m;i++){
        if(s[x][i] == 1) {y1 += 1*f[cot2];cot2++;}
        else if(s[x][i] == 2) {y1 += 2*f[cot2];cot2++;}
        else if(i == y) {y1 += 2*f[cot2];cot2++;}
    }
    if(fin(y1) == 1) return 0;
    return 1;
}
void dfs(int i,int ans1){
    if(i >= cnt) {
        ans = max(ans1,ans);
        return ;
    }
    int x = a[i], y = b[i];
    if(judge(x,y) == 1){
        s[x][y] = 2;
        dfs(i+1,ans1+1);
        s[x][y] = 0;
        dfs(i+1,ans1);
    }
    else dfs(i+1,ans1);
}

int main()
{
    while(scanf("%d %d %d",&n,&m,&l)!=EOF){
        ini(s,0);
        ans = 0;
        int t1,t2;
        for(int i = 0;i < l;i++) {
            scanf("%d%d",&t1,&t2);
            s[t1][t2] = 1;
        }
        int k = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(s[i][j] == 0) {a[k] = i,b[k] = j;k++;}
            }
        }
        cnt = k;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
