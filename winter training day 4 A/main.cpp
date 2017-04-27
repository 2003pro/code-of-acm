#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (j);i < (int)(k);i++)
using namespace std;
const int N = 200003;
int st[N],st1[N],st2[N];
vector<vector<int> > sr(N);
vector<vector<int> > srt(N);
vector<vector<int> > sr1(N);
vector<vector<int> > sr2(N);
int findst(int x){
    if(x == st[x]) return x;
    else return st[x] =  findst(st[x]);
}
void unionst(int x,int y){
    int fx = findst(x);
    int fy = findst(y);
    st[fy] = fx;
}
int findst1(int x){
    if(x == st1[x]) return x;
    return st1[x] =  findst1(st1[x]);
}
void unionst1(int x,int y){
    int fx = findst1(x);
    int fy = findst1(y);
    st1[fy] = fx;
}

int main()
{
    int n,k,l,x,y;
    scanf("%d%d%d",&n,&k,&l);
    rep(i,1,n+1) st[i] = st1[i] = i ;
    rep(i,0,k){
        scanf("%d %d",&x,&y);
        unionst(x,y);
    }
    rep(i,0,l){
        scanf("%d %d",&x,&y);
        unionst1(x,y);
    }
    rep(i,1,n+1) st[i] = findst(st[i]),st1[i] = findst1(st1[i]);
    rep(i,1,n+1) sr[st[i]].push_back(i),srt[st1[i]].push_back(i);
    rep(i,1,n+1) {
        sr1[i].assign(sr[st[i]].begin(),sr[st[i]].end());
        sr2[i].assign(srt[st1[i]].begin(),srt[st1[i]].end());
    }
    rep(i,1,n+1){
//        printf("%d %d\n",sr1[i].size(),sr2[i].size());
        sr1[i].insert(sr1[i].end(),sr2[i].begin(),sr2[i].end());
        sort(sr1[i].begin(),sr1[i].end());
        int l = sr1[i].size();
        int l1 = unique(sr1[i].begin(),sr1[i].end()) - sr1[i].begin();
//        for(int j = 0;j < sr2[i].size();j++) printf("%d\n",sr2[i][j]);
        printf("%d ",l-l1);
    }
    return 0;
}
