#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
char s[1003][1003];
int n,m;
int row[1002],col[1003];
int main(){
    ini(row,0);ini(col,0);
    int sum = 0,sx,sy;
    bool flag = false;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%s",s[i]+1);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(s[i][j] == '*')row[i]++,col[j]++,sum++;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(s[i][j] == '*'){
                if(sum == row[i] + col[j] - 1) flag = true,sx = i,sy = j;
            }
            else {
                if(sum == row[i] + col[j]) flag = true,sx = i,sy = j;
            }
        }
    }
    if(flag) printf("YES\n%d %d\n",sx,sy);
    else printf("NO\n");
}
