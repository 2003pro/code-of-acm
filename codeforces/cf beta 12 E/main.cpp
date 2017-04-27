#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int a[1003][1003],n;
int s[1003][1003][2];
int main()
{
    scanf("%d",&n);
    ini(a,0);ini(s,0);
    for(int i = 0;i < n;i++){
        a[0][i] = i;
        s[0][i][0] = 1;s[i][i][1] = 1;
    }
    for(int i = 1;i < n;i++){
        a[i][0] = a[0][i];
        s[0][i][1] = 1;s[i][i][0] = 1;
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j) a[i][j] = 0;
            else {
                for(int k = 1;k < n;k++){
                    if(s[k][i][0] == 0 && s[k][j][1] == 0) {
                        a[i][j] = k;
                        s[k][i][0] = 1,s[k][j][1] = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
