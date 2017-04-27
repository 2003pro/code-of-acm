#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100000],b[100000];

int main()
{
    int n,j = 1;scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i = 0;i <= n;i++){
        if(a[i] >= j) j++;
    }
    printf("%d\n",j);
    return 0;
}
