#include <bits/stdc++.h>

using namespace std;
typedef pair<double,double> pdd;
pdd st;
struct cmp1{
    bool operator ()(double &a,double &b){
        return a > b;
    }
};
double getTime(double x,double y,double v){
    double x1 = x - st.first,y1 = y - st.second;
    double dis = sqrt(x1*x1 + y1*y1);
    return dis/v;
}
priority_queue<double,vector<double>,cmp1> p;
int main()
{
    int n;double tx,ty,tv;
    scanf("%lf %lf %d",&st.first,&st.second,&n);
    for(int i = 0;i < n;i++){
        scanf("%lf %lf %lf",&tx,&ty,&tv);
        double tt = getTime(tx,ty,tv);
        p.push(tt);
    }
    printf("%.17f",p.top());
    return 0;
}
