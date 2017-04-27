#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
struct node{
    int ti,v;
}rabi[100003];
int a[5001];
priority_queue<int> q;

bool cmp(struct node a,struct node b){
    return a.ti >b.ti ;
}

int main()
{
    while(!q.empty()) q.pop();
    int N; scanf("%d",&N);
    for(int i =0;i<N;i++) scanf("%d",&rabi[i].ti);
    for(int i =0;i<N;i++) scanf("%d",&rabi[i].v);
    memset(a,0,sizeof(a));
    sort(rabi,rabi+N,cmp);
    int sum = 0;
    for(int i =0;i<N;i++) a[rabi[i].ti]++;
    for(int i =0;i<N;i++)  {
        q.push(rabi[i].v);
        a[rabi[i].ti] --;
        if(a[rabi[i].ti] == 0) {
            sum+=q.top();
            q.pop();
        }
    }
    printf("%d\n",sum);
    return 0;
}
