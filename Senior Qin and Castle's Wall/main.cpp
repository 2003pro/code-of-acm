#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N1 = 200009;
struct node{
    long long l,r;
}side[N1];
long long  p[N1];
long long M,N,K;
long long a[N1];

bool cmp(struct node a,struct node b){
    if(a.l == b.l) return a.r<b.r;
    else return a.l<b.l;
}
bool cmp1(struct node a,struct node b){
    return a.l<b.l;
}
bool cmp2(struct node a,struct node b){
    return a.r<b.r;
}
bool cmp3(struct node a,struct node b){
    if(a.l == b.l) return a.r>b.r;
    else return a.l<b.l;
}
bool cmp4(struct node a,struct node b){
    if(a.r == b.r) return a.l>b.l;
    else return a.r<b.r;
}

void updata(long long pos,long long v){
    while(pos <= K){
        a[pos] += v;
        pos +=pos&-pos;
    }
}

long long read(long long pos){
    long long ans = 0;
    while(pos > 0){
        ans += a[pos];
        pos -= pos&-pos;
    }
    return ans;
}

void discretze(){
    long long l1,r1;
    for(long long j = 1;j<K+1;j++){
        l1 = side[j].l;r1 = side[j].r;
        side[j].l = l1*M + r1;
        side[j].r = l1*N + r1;
    }
//    for(long long j = 1;j < K+1;j++)printf("%lld %lld  c\n",side[j].l,side[j].r);
    sort(side+1,side+K+1,cmp1);
    memset(p,0,sizeof(p));
    for(long long j = 1;j<K+1;j++) p[j] = side[j].l;
    long long num = unique(p+1,p+K+1) - (p+1);
    for(long long j = 1;j < K+1;j++){
        side[j].l = lower_bound(p + 1,p + num + 1,side[j].l) - p;
    }
    sort(side+1,side+K+1,cmp2);
    memset(p,0,sizeof(p));
    for(long long j = 1;j<K+1;j++) p[j] = side[j].r;
    long long num1 = unique(p+1,p+K+1) - (p+1);
    for(long long j = 1;j < K+1;j++){
        side[j].r = lower_bound(p + 1,p + num1 + 1,side[j].r) - p ;
    }
}

int main()
{
        scanf("%lld%lld%lld",&K,&M,&N);
        for(long long j = 1;j<K+1;j++){
            scanf("%lld%lld",&side[j].l,&side[j].r);
        }
        discretze();
        sort(side+1,side+K+1,cmp);
        memset(a,0,sizeof(a));
//        for(long long j = 1;j < K+1;j++)printf("%lld %lld  s\n",side[j].l,side[j].r);
        long long sum = 0;
        for(long long j = 1;j < K+1;j++) {
                updata(side[j].r,1);
                sum += j - read(side[j].r );
        }
        memset(a,0,sizeof(a));
        sort(side+1,side+K+1,cmp3);
        long long sum1 = 0;
        for(long long j = 1;j < K+1;j++) {
                updata(side[j].r,1);
                sum1 += j - read(side[j].r );
        }
        memset(a,0,sizeof(a));
        sort(side+1,side+K+1,cmp4);
        long long sum2 = 0;
        for(long long j = 1;j < K+1;j++) {
                updata(side[j].l,1);
                sum2 += j - read(side[j].l );
        }
        printf("%lld\n",sum1+sum2-sum);
    return 0;
}
