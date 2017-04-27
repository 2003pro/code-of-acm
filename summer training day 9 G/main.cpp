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
char s[100004];
int main()
{
    scanf("%s",s);
    int l = strlen(s);
    int s1 = 0,s2 = 0;
    for(int i = 0;i < l;i++){
        if(s[i] == '0') s1++;
        else if(s[i] == '1') s2++;
    }
    printf("%d\n",min(s1,s2));
    return 0;
}
