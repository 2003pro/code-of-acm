#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const double eps = 1e-6;
const double PI = acos(-1.0);
bool zero(double x){
    return (x > 0?x:-x) < eps;
}
struct Point {
	double x, y;
	Point() {}
	Point(const double &_x, const double &_y) { x = _x; y = _y; }
	Point operator + (const Point &b) const {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (const double &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const double &k) const {
		return Point(x / k, y / k);
	}
	double operator * (const Point &b) const {
		return x * b.x + y * b.y;
	}
	double Abs() const {
		return sqrt(x * x + y * y);
	}
};
typedef Point Vector;
double getAngle(Vector a){
    Vector b = Vector(1,0);
    double t =  acos(a*b/a.Abs()/b.Abs());
    if(a.y < 0) t = -t;
    if(a.y == 0 && a.x < 0) t = -t;
    return t;
}
typedef pair<double,double> pdd;
pdd P[1003];Point a[4];
pdd solve(){
    double b[4];
    for(int i = 0;i < 4;i++) b[i] = getAngle(a[i]);
    if(a[0].x < 0 && a[0].y > 0 && a[2].x < 0 && a[2].y <= 0){
        b[0] = (b[0]-PI) - PI,b[1] = (b[1]-PI) - PI;
    }
    sort(b,b+4);
    pdd tt;tt.first = b[0],tt.second = b[3];
    return tt;
}
bool cmp1(pdd a1,pdd b1){
    if(!zero(a1.second-b1.second))return a1.second < b1.second;
    else return a1.first > b1.first;
}
int main()
{
//    Vector t = Vector(1,-1);
//    printf("%f",getAngle(t));
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%lf%lf",&a[2].x,&a[2].y);
        scanf("%lf%lf",&a[1].x,&a[1].y);
        a[0].x = a[2].x,a[0].y = a[1].y;
        a[3].x = a[1].x,a[3].y = a[2].y;
        P[i] = solve();
    }
    sort(P,P+n,cmp1);double t = P[0].second;int cnt = 1;
    for(int i = 1;i < n;i++){
        if(t < P[i].first) {t = P[i].second;cnt++;}
    }
    printf("%d\n",cnt);
    return 0;
}
