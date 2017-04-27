#include <bits/stdc++.h>

using namespace std;
const int N = 70003;
typedef pair<int,int> pii;
struct interest{
    int uid,cid,ct,hc;
}inte[N];
struct event{
    int uid,cid,aid,st,cf;
};
struct join{
    int uid,cid,ct,hc,aid,st,cf;
}joi[N];
map<pii,interest> check;
map<pii,vector<int> > reche;
vector<join> result;
bool cmp(struct join a,struct join b){
    if(a.hc != b.hc) return a.hc < b.hc;
    else if(a.uid != b.uid) return a.uid < b.uid;
    else if(a.cid != b.cid) return a.cid < b.cid;
    else if(a.ct != b.ct) return a.ct < b.ct;
    else if(a.aid != b.aid) return a.aid < b.cid;
    else if(a.st != b.st) return a.st < b.st;
}
int res[N];
int main()
{
    int ic,ec,a,b,c,d,e;struct event tmp;
    scanf("%d %d",&ic,&ec);
    for(int i = 0;i < ic;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        inte[i].uid = a,inte[i].cid = b,inte[i].ct = c,inte[i].hc = d;
        pii p;p.first = a,p.second = b;
        check[p] = inte[i];
        reche[p].push_back(c);
    }
    int cnt = 0;
    for(int i = 0;i < ec;i++) res[i] = INT_MAX;   d
    for(int i = 0;i < ec;i++){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        tmp.uid = a,tmp.cid = b,tmp.aid = c,tmp.st = d,tmp.cf = e;
        pii p;p.first = a,p.second = b;
        struct interest tt = check[p];
        int tis = d - tt.ct;
        if(tis > 0 && tis < res[reche[p]]) {
            res[reche[p]] = tis;
            joi[reche[p]].uid = a,joi[reche[p]].cid = b,joi[reche[p]].ct = tt.ct,joi[reche[p]].hc = tt.hc;
            joi[reche[p]].aid = c,joi[reche[p]].st = d,joi[reche[p]].cf = e;
        }
    }
    for(int i = 0;i < ic;i++){
        if(res[i] != INT_MAX) {result.push_back(joi[i]);cnt++;}
    }
    sort(result.begin(),result.end(),cmp);
    printf("%d\n",cnt);
    for(int i = 0;i < cnt;i++){
        printf("%d %d %d %d %d %d %d\n",result[i].uid,result[i].cid,result[i].ct,result[i].hc,result[i].aid,result[i].st,result[i].cf);
    }
    return 0;
}
