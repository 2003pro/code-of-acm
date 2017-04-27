#include <iostream>
#include <cstdio>
#include <cstring>
int a[100003],s[100003];

int main()
{
    int N,M,Q,le = 0,b,c;
    memset(s,0,sizeof(s));
    scanf("%d%d%d",&N,&M,&Q);
    for(int i = 1;i <= N;i++) {
        scanf("%d",&a[i]);
        s[a[i]]++;
    }
    for(int i = 1;i <= M;i++){
        if(s[i]!=0) le++;
    }
    for(int i = 1;i <= Q;i++){
        scanf("%d%d",&b,&c);
        if(s[c] == 0) le++;
        if(s[a[b]] == 1) le--;
        if(s[a[b]] >= 1) s[a[b]]--;
        s[c]++;
        a[b] = c;
        printf("%d\n",M-le);
    }
    return 0;
}
