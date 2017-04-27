#include <vector>
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
#define sqr(a) (a*a)
using namespace std;

class BearNSWE {
public:
	double totalDistance(vector <int> a, string dir){
        double sum = 0;double x = 0.0,y = 0.0;
        int l = a.size();
        for(int i = 0;i < l;i++) sum += a[i];
        for(int i = 0;i < l;i++){
            if(dir[i] == 'N') y += 1.0*a[i];
            else if(dir[i] == 'E') x += 1.0*a[i];
            else if(dir[i] == 'W') x -= 1.0*a[i];
            else if(dir[i] == 'S') y -= 1.0*a[i];
        }
        sum += sqrt(sqr(x) + sqr(y));
        return sum;
	}
};




//Powered by [KawigiEdit] 2.0!
