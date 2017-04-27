#include <bits/stdc++.h>

using namespace std;
const int N = 21;
char s[N*N][N*N];

int main()
{
    int n,k,a;
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(k != 0){
                s[i][j] = '*';k--;
            }
            else s[i][j] = '.';
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int i1 = 0;i1 < n;i1++){
                for(int j1 = 0;j1 < n;j1++){
                        s[i1 + i*n][j1 + j*n] = s[(i1+j)%n][(j1+i)%n];
                }
            }
        }
    }
    for(int i = 0;i < n*n;i++){
        for(int j = 0;j < n*n;j++){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
