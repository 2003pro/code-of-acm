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

using namespace std;

class TriangleMaking {
public:
	int maxPerimeter(int, int, int);
};

int TriangleMaking::maxPerimeter(int a, int b, int c) {
	int pe = 0,a1 = a,b1 = b,c1 = c;
    if(b1 < c1){int t = b1;b1 = c1;c1 = t;}
    if(a1 < b1){int t = a1;a1 = b1;b1 = t;}
    if(b1+c1 > a1) pe = a1+b1+c1;
    else pe = 2*(b1+c1)-1;
    return pe;
}


