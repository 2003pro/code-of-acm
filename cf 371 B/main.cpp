#include <bits/stdc++.h>

using namespace std;
int a[100003],b[3];
int check(int aa){
    int cc = 0;
    for(int i = 0;i < 3;i++){
        if(b[i] != aa && b[i] == -1) {b[i] = aa;return 1;}
        else if(b[i] != aa) cc++;
        else if(b[i] == aa) return 0;
    }
    return 1;
}
int main()
{
    int n,cnt = 0;
    memset(b,-1,sizeof(b));
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%d",&a[i]);
        if(check(a[i])) cnt++;
        if(cnt > 3) {printf("NO\n");return 0;}
    }
    if(cnt <= 2) printf("YES\n");
    else {
        sort(b,b+3);
        if(b[2] + b[0] == 2*b[1]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
