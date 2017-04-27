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

class BearPasswordAny {
public:
	string findPassword(vector <int> a){
        int l = a.size();
        for(int i = 0;i < l;i++){
            if(a[i]*(i+1) > l) return "";
        }

	}
};


//Powered by [KawigiEdit] 2.0!
