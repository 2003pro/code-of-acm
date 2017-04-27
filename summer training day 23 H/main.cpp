#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;
struct Point {
	double x, y;
	Point() {}
	Point(const double &_x, const double &_y) { x = _x; y = _y; }
	void Read() { scanf("%lf%lf", &x, &y); }
}soba[103],noba[103];
double getDis(struct Point a,struct Point b){
    double dx = a.x - b.x,dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}
int main()
{
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    int n,w;scanf("%d",&n);
    double ans = 0;
    for(int i = 0;i <= n;i++) soba[i].Read();
    scanf("%d",&w);
    for(int i = 0;i <= n;i++) noba[i].x = soba[i].x,noba[i].y = soba[i].y+w;
    for(int i = 1;i <= n;i++){
        if((soba[i-1].y >= soba[i].y && soba[i-1].y <= noba[i].y) || (noba[i-1].y >= soba[i].y && noba[i-1].y <= noba[i].y)){
            ans += soba[i].x - soba[i-1].x;
        }
        else {
            double a1 = getDis(soba[i-1],noba[i]),a2 = getDis(noba[i-1],soba[i]);
            ans += min(a1,a2);
        }
    }
    printf("%.17f\n",ans);
    return 0;
}
