#include <bits/stdc++.h>
#define in freopen("king.in","r",stdin)
#define out freopen("king.out","w",stdout)
using namespace std;
struct date
{
    friend bool operator< (date n1, date n2)
    {
        if(n1.year != n2.year) return n1.year < n2.year;
        else if(n1.mon != n2.mon) return n1.mon < n2.mon;
        return n1.day < n2.day;
    }
    int day,mon,year,id;
}dat[103];
const int days = 365;
const int s[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int da,ma,ya;
bool Isleap(int y){
    if(y%400 == 0||y%100 && y%4 == 0) return 1;
    return 0;
}
int leap(int y){
    if(!y) return 0;
    return y/4-y/100+y/400;
}
int calc(int day,int mon,int year){
    int res = (year-1)*days + leap(year-1);
    for(int i = 1;i < mon;i++){
        res += s[i];
    }
    if(Isleap(year) && mon > 2) res++;
    res += day;
    return res;
}
int count_day(int db,int mb,int yb){
    int resa = calc(da,ma,ya);
    int resb = calc(db,mb,yb);
    return abs(resa-resb);
}
priority_queue<date> q;
int main()
{
    scanf("%d%d%d",&da,&ma,&ya);
    int n,a,b,c;scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&a,&b,&c);
        struct date t;t.day = a,t.mon = b,t.year = c,t.id = i;
        q.push(t);
    }
    while(!q.empty()){
        struct date t = q.top();q.pop();
        int cn = 0;
        if(t.mon < ma)
            cn = ya - t.year;
        else if(t.mon == ma &&t.day <= da)
            cn = ya - t.year;
        else cn = ya - t.year - 1;
        if(cn >= 18) {printf("%d\n",t.id);return 0;}
    }
    printf("-1\n");
    return 0;
}
