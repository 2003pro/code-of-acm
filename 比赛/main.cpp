#include <bits/stdc++.h>

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
	void Read() { scanf("%lf%lf", &x, &y); }
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
	double Angle() const {
		return atan2(y, x);
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
int main()
{
    Vector t = Vector(-1,1);
    printf("%f",getAngle(t));
}
