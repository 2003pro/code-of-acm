#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int N1 = 1000009;
struct node{
    int wei,loc;
    bool operator<(const node  &b)const {
        return (this->wei<b.wei);
    }
}a[N1];

int b[N1],c[N1],B[N1];
set <node> s;

int bfind(int len,int w){
    int left = 0, right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right-left)/2;
        if (B[mid] > w)
            right = mid - 1;
        else if (B[mid] < w)
            left = mid + 1;
        else    //�ҵ��˸�Ԫ�أ���ֱ�ӷ���
            return mid;
    }
    return left;//����b�в����ڸ�Ԫ�أ��򷵻ظ�Ԫ��Ӧ�ò����λ��
}

int LIS(int M){
    int len =1;
    B[0] = c[0];
    int i, pos = 0;
    for(i=1; i<M; ++i)
    {
        if(c[i] > B[len-1]) //�������B������Ԫ�أ���ֱ�Ӳ��뵽B����ĩβ
        {
            B[len] = c[i];
            ++len;
        }
        else
        {
            pos = bfind(len, c[i]); //���ֲ�����Ҫ�����λ��
            B[pos] = c[i];
        }
    }
    return len;
}

int solve(int M){
    set <node>::iterator it;
    int tmp = 0;
    for(int i = 1; i <=M;i++) {
        node t;
        t.wei = b[i];
        it = s.find(t);
        if(it != s.end()) {c[tmp] = (*it).loc;tmp++;}
    }
    if(c[0] == 0) return 0;
    return LIS(M);
}

int main()
{
    memset(c,0,sizeof(c));
    memset(b,0,sizeof(b));
    memset(B,0,sizeof(B));
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i = 1;i <= N;i++) {scanf("%d",&a[i].wei); a[i].loc = i; s.insert(a[i]);}
    for(int i = 1;i <= M;i++) scanf("%d",&b[i]);
    printf("%d\n",solve(M)+1);
    return 0;
}
