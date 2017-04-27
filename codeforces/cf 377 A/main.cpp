#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,r;
    scanf("%d%d",&k,&r);
    int an = 1;
    if(k == r || k == 10 || 10 + r == k) printf("1\n");
    else {
        while(k*an % 10 != 0 && (k*an-r) % 10 != 0) an++;
        printf("%d\n",an);
    }
    return 0;
}
