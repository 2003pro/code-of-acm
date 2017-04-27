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

class DivisibleSetDiv2 {
public:
	string isPossible(vector <int>);
};

string DivisibleSetDiv2::isPossible(vector <int> b) {
	int l = b.size(),mi = 11;
	for(int i = 0;i < l;i++){mi = min(mi,b[i]);}
	string s1 = 'Possible',s2 = 'Impossible';
    if(mi >= l)return s1;
    else return s2;
}
