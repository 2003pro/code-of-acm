#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
struct node{
    int xi,xj,val;
    friend bool operator <(const node &a,const node &b){return a.val>b.val;}
};
int N;
int a[100009],b[100009];
priority_queue<node> q;
set <int> s;

int main()
{
    scanf("%d",&N);
    for(int i = 0;i < N;i++) scanf("%d",&a[i]);
    for(int i = 0;i < N;i++) scanf("%d",&b[i]);
    sort(a,a+N);
    sort(b,b+N);
    int j = 0,i = 0;
    s.insert(i*100000+j);
    node s1;
    s1.xi = 0;s1.xj = 0;s1.val = a[0] + b [0];
    q.push(s1);
    for(int k = 0;k < N; k++){
        node t1 = q.top(); q.pop();
        i = t1.xi; j = t1.xj;
        printf("%d\n",t1.val);
        if(s.find((i+1) * 100000 + j) == s.end()) {
            s.insert((i+1) * 100000 + j);
            s1.xi = i+1;s1.xj = j;s1.val = a[i+1] + b [j];
            q.push(s1);
        }
        if(s.find(i * 100000 + j+1) == s.end()) {
            s.insert(i * 100000 + j+1);
            s1.xi = i;s1.xj = j+1;s1.val = a[i] + b [j+1];
            q.push(s1);
        }
    }
    return 0;
}
