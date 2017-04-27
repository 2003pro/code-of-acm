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
int s[103];
int main()
{
    int T,n;scanf("%d",&T);
    for(int l = 1;l <= T;l++){
        scanf("%d",&n);int flag = 1,t;
        for(int i = 0;i < n;i++) {
            scanf("%d",&t);
            if(t%3 != 0) flag = 0;
        }
        printf("Case #%d: ",l);
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
