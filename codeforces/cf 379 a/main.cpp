#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[2],n;
    char c;
    a[0] = 0,a[1] = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {scanf("%c",&c);a[(c-'A')%2]++;}
    if(a[0] == a[1]) printf("Friendship\n");
    else if(a[0] > a[1]) printf("Anton\n");
    else printf("Danik\n");
    return 0;
}
