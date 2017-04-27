#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,t,t1,flag = 0;scanf("%d %d",&n,&t);
    if(n == 1) {
        if(t == 15) printf("DOWN\n");
        else if(t == 0) printf("UP\n");
        else printf("-1\n");
        return 0;
    }
    for(int i = 1;i < n - 1;i++){
        scanf("%d",&t1);t = t1;
    }
    scanf("%d",&t1);
    if(t1 > t && t1 != 15) flag = 1;
    else if(t1 == 15) flag = 0;
    else if(t1 < t && t1 != 0) flag = 0;
    else if(t1 == 0) flag = 1;
    if(flag) printf("UP\n");
    else printf("DOWN\n");
    return 0;
}
