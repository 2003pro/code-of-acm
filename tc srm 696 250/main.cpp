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

class Ropestring {
public:
	string makerope(string);
};
string ans;
vector<int> v1,v2;
bool cmp(int a,int b){
    return a > b;
}
string Ropestring::makerope(string s) {
    int l = s.length();
    for(int i = 0;i < l;i++){
        if(s[i] == '.') continue;
        else{
            int cnt = 0;
            while(s[i] != '.' && i < l) cnt++,i++;
            if(cnt % 2 == 0)v1.push_back(cnt);
            else v2.push_back(cnt);
        }
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    int k = 0,n1 = v1.size(),n2 = v2.size();
    for(int i = 0;i < n1;i++){
        while(v1[i]--)ans += '-',k++;
        if(k < l)ans += '.',k++;
    }
    for(int i = 0;i < n2;i++){
        while(v2[i]--)ans += '-',k++;
        if(k < l)ans += '.',k++;
    }
    while(k < l)ans += '.',k++;
    return ans;
}

