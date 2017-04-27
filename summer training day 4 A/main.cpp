#include <bits/stdc++.h>

using namespace std;
struct node{
    int x,y,a;
}se[10003];
int n,m,s[103][103];
int solve(int x,int y){
    int a0 = 0,a1 = 0,a2 = 0,a3 = 0;
    for(int i = 1;i <= n;i++){
        if(s[i][x] == 0&&s[i][y] == 0) a0++;
        if(s[i][x] == 0&&s[i][y] == 1) a1++;
        if(s[i][x] == 1&&s[i][y] == 0) a2++;
        if(s[i][x] == 1&&s[i][y] == 1) a3++;
    }
    return max(max(a0,a1),max(a2,a3));
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%d",&s[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 1;i < m;i++){
        for(int j = i+1;j <= m;j++){
            node t;
            t.x = i,t.y = j,t.a = solve(i,j);
            se[cnt] = t;
            cnt++;
        }
    }
    node temp = se[0];
    for(int i = 1;i < cnt;i++){
        if(temp.a > se[i].a) temp = se[i];
    }
    printf("%d\n%d %d\n",temp.a,temp.x,temp.y);
    return 0;
}
