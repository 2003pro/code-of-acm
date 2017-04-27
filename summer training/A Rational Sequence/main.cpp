#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>

using namespace std;

map<pair<int ,int>,int> num;
map<pair<int ,int>,pair<int ,int> > father;
int cl[33] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};

int findLevel(int l,int r){
    int sum = 1;
    pair<int,int> p,p1;
    p = make_pair(l,r);
    while(l != 1||r != 1){
        if(l > r){
            l -= r;
            sum++;
            p1 = make_pair(l,r);
            father[p] = p1;
            p = p1;
        }
        else {
            r -= l;
            sum++;
            p1 = make_pair(l,r);
            father[p] = p1;
            p = p1;
        }
    }
    return sum;
}

int findNum(int l,int r){
    int r1;
    pair<int,int> t = make_pair(l,r);
    if(num[t]) return num[t];
    pair<int,int> p = father[t];
    if(l > r)  r1 = (findNum(p.first,p.second) - cl[findLevel(father[p].first,father[p].second)] - 1) * 2 + 2;
    else r1 = (findNum(p.first,p.second) - cl[findLevel(father[p].first,father[p].second)] - 1) * 2 + 1;
    num[p] = findLevel(p.first,p.second) + r1;
    return num[p];
}

int main(){
    int T,c,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d/%d",&c,&a,&b);
        findLevel(a,b);
        printf("%d %d\n",c,findNum(a,b));
    }
    return 0;
}
