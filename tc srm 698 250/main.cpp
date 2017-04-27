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

class Initials {
public:
	string getInitials(string);
};

string Initials::getInitials(string name) {
	string ans;
	ans += name[0];
    int l = name.length();
    for(int i = 1;i < l;i++){
        if(name[i] == ' ') ans += name[i+1];
    }
    return ans;
}

