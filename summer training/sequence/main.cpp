#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    int a[] = {0,1, 2, 4, 8, 16, 23, 46, 29, 58, 116, 223, 446, 289, 578, 1156, 1223, 2446, 2489, 4789, 5789, 11578, 12356, 12247, 24449};
    int b[] = {244445,48889, 77789, 155578, 111356, 122227};
    scanf("%d",&n);
    if(n < 25) printf("%d\n",a[n]);
    else {
        int t = (n - 24)%6;
        printf("%d\n",b[t]);
    }
    return 0;
}
