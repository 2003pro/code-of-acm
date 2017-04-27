#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
#define rep(i,j,k) for(int i = (int)j;i < (int)k;i++)
using namespace std;
char s[23];
char ss[] = {'0','e','n','o','+'};
int main()
{
    int n,sum = 2;scanf("%d",&n);
    rep(i,0,n){
        int flag[5];ini(flag,0);
        scanf("%s",s);
        int l = strlen(s);
        for(int i = 1;i <=4;i++){
            if(s[l-i] == ss[i]) flag[i] = 1;
        }
        if(flag[1]&&flag[2]&&flag[3]&&flag[4]) sum += 2;
        else sum++;
    }
    if(sum == 13) printf("1400\n");
    else printf("%d\n",sum*100);
    return 0;
}
