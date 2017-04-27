#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ini(x,y) memset(x,y,sizeof(x));

using namespace std;
int n,l,p;
struct node{
    int dis,fuel;
}st[10003];
priority_queue<int> que;
bool cmp(const node a,const node b){
    return a.dis < b.dis;
}
int main()
{
    scanf("%d",&n);int x,y;
    for(int i = 0;i < n;i++) {scanf("%d %d",&x,&y);st[i].dis = x,st[i].fuel = y;}
    scanf("%d%d",&l,&p);st[n].dis = l,st[n].dis = 0;n++;
    for(int i = 0;i < n;i++) st[i].dis = l - st[i].dis;
    sort(st,st+n,cmp);
    int ans = 0,now = 0,con = p;
    for(int i = 0;i < n;i++){
        int d = st[i].dis - now;
        while(con - d < 0){
            if(que.empty()){printf("-1\n");return 0;}
            con += que.top();que.pop();
            ans++;
        }
        con -= d;
        now = st[i].dis;
        que.push(st[i].fuel);
    }
    printf("%d\n",ans);
    return 0;
}
