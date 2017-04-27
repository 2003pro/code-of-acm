#include <bits/stdc++.h>
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)
using namespace std;
int ch = 60;
int cd = 24*ch;
int cy = 365*cd;
int mo[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int mo1[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int cal(int s){
    int sum = 0;
    for(int i = 0;i <= s;i++) sum += mo[i];
    return sum;
}
int cal1(int s){
    int sum = 0;
    for(int i = 0;i <= s;i++) sum += mo1[i];
    return sum;
}
typedef struct node{
    int val,fl;
};
bool cmp(const node &a,const node &b){
    if(a.val != b.val)return a.val < b.val;
    else return a.fl < b.fl;
}
vector<node> v;
priority_queue<int> p;
int main()
{
//    in;out;
    int T;scanf("%d",&T);
    int b,c,y,m,d,h,mi;
    char t[25];
    while(T--){
        scanf("%d %d",&b,&c);
        for(int i = 0;i < b;i++){
            scanf("%s",t);
            struct node tt,tt1;tt.fl = 0,tt1.fl = 1;
            scanf("%d-%d-%d%d:%d",&y,&m,&d,&h,&mi);
            if(y < 2016) tt.val = (y-2013)*cy + cal(m-1)*cd + d*cd + h*ch + mi;
            if(y == 2016) tt.val = (y-2013)*cy + cal1(m-1)*cd + d*cd + h*ch + mi;
            v.push_back(tt);
            printf("%d\n",tt.val);
            scanf("%d-%d-%d%d:%d",&y,&m,&d,&h,&mi);
            if(y < 2016) tt1.val = (y-2013)*cy + cal(m-1)*cd + d*cd + h*ch + mi;
            if(y == 2016) tt1.val = (y-2013)*cy + cal1(m-1)*cd + d*cd + h*ch + mi + c;
            v.push_back(tt1);
            printf("%d\n",tt1.val);
        }

        printf("%d\n",ma);
    }
    return 0;
}
