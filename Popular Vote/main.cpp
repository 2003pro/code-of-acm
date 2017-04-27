#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct node{
    int vote,num;
    friend bool operator<(node a,node b){
        return a.vote < b.vote;
    }
}tmp[13];

priority_queue <node> s;

void utilize(){
    for(int i = 0;i < 13 ;i++){
        tmp[i].vote = 0;
        tmp[i].num = i;
    }
    while(!s.empty()) s.pop();
}

int main()
{
    int T,n;
    struct node a,b;
    scanf("%d",&T);
    while(T--) {
        utilize();
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&tmp[i].vote);
            s.push(tmp[i]);
        }
        a = s.top(); s.pop();
        b = s.top();
        if(a.vote == b.vote) printf("no winner\n");
        else printf("majority winner %d\n",a.num+1);
    }
    return 0;
}
