#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
struct node{
    int b[5][5];
}s[10];
int a[10][5][5][5],vis[10];
bool flag = true;
bool judge(){
    bool ff = true;
    for(int i = 1;i <=4 ;i++){
        if(s[1].b[i][4] != s[2].b[i][1]) ff = false;
        if(s[2].b[i][4] != s[3].b[i][1]) ff = false;
        if(s[4].b[i][4] != s[5].b[i][1]) ff = false;
        if(s[5].b[i][4] != s[6].b[i][1]) ff = false;
        if(s[7].b[i][4] != s[8].b[i][1]) ff = false;
        if(s[8].b[i][4] != s[9].b[i][1]) ff = false;
        if(s[1].b[4][i] != s[4].b[1][i]) ff = false;
        if(s[4].b[4][i] != s[7].b[1][i]) ff = false;
        if(s[2].b[4][i] != s[5].b[1][i]) ff = false;
        if(s[5].b[4][i] != s[8].b[1][i]) ff = false;
        if(s[3].b[4][i] != s[6].b[1][i]) ff = false;
        if(s[6].b[4][i] != s[9].b[1][i]) ff = false;
    }
    return ff;
}
void output(){
    int k = 0;
    for(int i = 1;i <= 3;i++)
        printf("%d %d %d %d %d %d %d %d %d %d\n",s[1+3*k].b[i][1],s[1+3*k].b[i][2],s[1+3*k].b[i][3],s[2+3*k].b[i][1],s[2+3*k].b[i][2],s[2+3*k].b[i][3],s[2+3*k].b[i][4],s[3+3*k].b[i][2],s[3+3*k].b[i][3],s[3+3*k].b[i][4]);
    k = 1;
    for(int i = 1;i <= 4;i++)
        printf("%d %d %d %d %d %d %d %d %d %d\n",s[1+3*k].b[i][1],s[1+3*k].b[i][2],s[1+3*k].b[i][3],s[2+3*k].b[i][1],s[2+3*k].b[i][2],s[2+3*k].b[i][3],s[2+3*k].b[i][4],s[3+3*k].b[i][2],s[3+3*k].b[i][3],s[3+3*k].b[i][4]);
    k = 2;
    for(int i = 2;i <= 4;i++)
        printf("%d %d %d %d %d %d %d %d %d %d\n",s[1+3*k].b[i][1],s[1+3*k].b[i][2],s[1+3*k].b[i][3],s[2+3*k].b[i][1],s[2+3*k].b[i][2],s[2+3*k].b[i][3],s[2+3*k].b[i][4],s[3+3*k].b[i][2],s[3+3*k].b[i][3],s[3+3*k].b[i][4]);
    exit(0);
}
void dfs(int w){
    if(w == 10){
        if(judge()) output();
        return ;
    }
    for(int l = 1;l <=9 ;l++){
        if(vis[l]) continue;
        for(int k = 0;k < 4;k++){
            for(int i = 1;i <= 4;i++){
                for(int j = 1;j <= 4;j++){
                    s[w].b[i][j] = a[l][i][j][k];
                }
            }
            vis[l] = 1;
            dfs(w+1);
        }
        vis[l] = 0;
    }
}
int main()
{
    for(int i = 1;i <= 9;i++){
        for(int j = 1;j <= 4;j++){
            for(int k = 1;k <= 4;k++){
                scanf("%d",&a[i][0][j][k]);
            }
        }
    }
    for(int l = 1;l <= 9;l++){
        for(int k = 2;k <= 4;k++){
            for(int i = 1;i <= 4;i++){
                for(int j = 1;j <= 4;j++){
                    a[l][j][4-i-1][k] = a[l][i][j][k-1];
                }
            }
        }
    }
//    dfs(1);
//    printf("---------\n");
//    for(int l = 1;l <= 4;l++){
//        for(int i = 1;i <= 4;i++){
//            for(int j = 1;j <= 4;j++){
//                printf("%d ",a[1][i][j][l]);
//            }
//            printf("\n");
//        }
//        printf("---\n");
//    }
    return 0;
}
