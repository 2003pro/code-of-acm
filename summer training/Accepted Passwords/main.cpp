#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char a[103],b[103],c[103][103];
int m =0,n =0;

int lcs(){
    for(int i = 0;i <= m;i++) c[i][0] = 0;
    for(int i = 0;i <= n;i++) c[0][i] = 0;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(a[i-1] == b[j-1]) c[i][j] = c[i-1][j-1] + 1;
            else if(c[i-1][j] >= c[i][j-1]) c[i][j] = c[i-1][j];
            else c[i][j] = c[i][j-1];
        }
    }
    return c[m][n];
}

int main()
{
    scanf("%s %s",&a,&b);
    m = strlen(a), n = strlen(b);
    int k = 0,cnt = 0;
    if(abs(m - n) > 1 || (m - n) == -1) printf("no\n");
    else {
        k = lcs();
        if(m < 8){
            if(k == m) printf("yes\n");
            else printf("no\n");
        }
        else if(m >= 8 && abs(m-k) <= 1) {
            if(m == k) printf("yes\n");
            else {
                for(int i = 0;i <= m;i++) if(a[i] != b[i]) {cnt = i;break;}
                if(m - n == 1){
                    for(int i = cnt + 1;i <= m;i++) if(a[i] != b[i-1]) {printf("no\n");return 0;}
                    printf("yes\n");
                }
                else {
                    for(int i = cnt + 1;i <= m;i++) if(a[i] != b[i]){printf("no\n");return 0;}
                    printf("yes\n");
                }
            }
        }
        else printf("no\n");
    }
    return 0;
}
