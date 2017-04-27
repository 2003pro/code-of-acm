#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int a1[100003];
    char s[100003];
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i = 0;i<n;i++) scanf("%d",&a1[i]);
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == '>') sum+=a1[i];
        else if(s[i] == '<') sum-=a1[i];
        if(sum <= 0 || sum >n) break;
    }
    if(sum>0 && sum <=n) printf("INFINITE\n");
    else printf("FINITE\n");
    return 0;
}
