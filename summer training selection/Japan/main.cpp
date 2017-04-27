#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N1 = 10003;
struct node{
    int l,r;
}side[N1*N1];
int M,N,K;
long long a[1000003];

bool cmp(struct node a,struct node b){
    if(a.l == b.l) return a.r<b.r;
    else return a.l<b.l;
}

void updata(int pos,long long v){
    while(pos <= M){
        a[pos] += v;
        pos +=pos&-pos;
    }
}

long long read(int pos){
    long long ans = 0;
    while(pos > 0){
        ans += a[pos];
        pos -= pos&-pos;
    }
    return ans;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&N,&M,&K);
        for(int j = 1;j<K+1;j++){
            scanf("%d%d",&side[j].l,&side[j].r);
        }
        sort(side+1,side+K+1,cmp);
//        for(int j = 1;j<K+1;j++){printf("%d %d s\n",side[j].l,side[j].r);}
        long long sum = 0;
        for(int j = 1;j < K+1;j++) {
                updata(side[j].r,1);
                sum += j - read(side[j].r );
//                printf("%lld  n\n",sum);
        }
        printf("Test case %d: %lld\n",i+1,sum);
    }
    return 0;
}
