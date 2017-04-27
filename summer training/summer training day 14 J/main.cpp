#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;
bool zero(double x){
    return (x > 0?x:-x) < eps;
}
struct Point {
	double x, y, z;
	Point() {}
	Point(const double &_x, const double &_y, const double &_z) { x = _x; y = _y; z = _z;}
	void Read() { scanf("%lf%lf%lf", &x, &y,&z); }
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y, z - b.z);
	}
	Point operator * (const double &k) const {
		return Point(x * k, y * k,z * k);
	}
	double operator * (const Point &b) const {
		return x * b.x + y * b.y + z * b.z;
	}
	Point operator ^ (const Point &b) const {
        Point ret;
        ret.x=y*b.z-z*b.y;
        ret.y=z*b.x-x*b.z;
        ret.z=x*b.y-y*b.x;
        return ret;
	}
    double Abs() const {
		return sqrt(x * x + y * y + z * z);
	}
};
typedef Point Vector;
Vector getP(Point a,Point b,Point c){
    return (a - b)^(b - c);
}
bool judge(Point a,Point b,Point c,Point d){
    return zero(getP(a,b,c)*(d - a));
}
int main()
{
    Point a[4];double d[4];
    for(int i = 0;i < 4;i++) a[i].Read();
    Vector x1 = a[0] - a[1],y1 = a[3] - a[2];
    if(zero(x1*y1) && judge(a[0],a[1],a[2],a[3])){
        Point inter = a[0];
        double t=((a[0].x-a[2].x)*(a[2].y-a[3].y)-(a[0].y-a[2].y)*(a[2].x-a[3].x))/((a[0].x-a[1].x)*(a[2].y-a[3].y)-(a[0].y-a[1].y)*(a[2].x-a[3].x));
        inter.x+=(a[1].x-a[0].x)*t;
        inter.y+=(a[1].y-a[0].y)*t;
        inter.z+=(a[1].z-a[0].z)*t;
        for(int i = 0;i < 4;i++){
            Vector tt = inter - a[i];
            d[i] = tt.Abs();
        }
        double d1 = x1.Abs(),d2 = y1.Abs();
        if(zero(d[0]-d[1]-d1)&&zero(d[3]-d[2]-d2)) printf("Valid\n");
        else printf("Invalid\n");
    }
    else printf("Invalid\n");
    return 0;
}
