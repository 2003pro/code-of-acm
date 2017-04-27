#include <bits/stdc++.h>

using namespace std;
const int N = 200003;
int color[N],mp[N],sock[N],father[N];
vector<int>  re[N];
int findf(int x){
    if(father[x] == x) return x;
    else return father[x] = findf(father[x]);
}
int main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&sock[i]);
        father[i] = i;
    }
    int x,y,fx,fy;
    for(int i = 1;i <= m;i++) {
        scanf("%d%d",&x,&y);
        fy = findf(y),fx = findf(x);
        if(fy != fx) father[fy] = fx;
    }
    int k1 = 0;
    int an = 0,t;
    for(int i = 1;i <= n;i++) re[findf(i)].push_back(i);
//    printf("%d\n",k1);
//    for(int i = 0;i < k1;i++){
//        for(int j = 0;j < re[i].size();j++) printf("%d\n",re[i][j]);
//        printf("---\n");
//    }
    for(int i = 1;i <= n;i++){
        if(findf(i) == i){
            for(int j = 0;j < re[i].size();j++) color[sock[re[i][j]]] = 0;
            t = 0;
            for(int j = 0;j < re[i].size();j++) {color[sock[re[i][j]]]++;t = max(t,color[sock[re[i][j]]]);}
            an += re[i].size() - t;
        }
    }
    printf("%d\n",an);
    return 0;
}
