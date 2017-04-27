#include <iostream>
#include <cstdio>
#include <cstring>

int gl[20][20];

int main()
{
    int a,b,ans  = 0;
    scanf("%d%d",&a,&b);
    gl[0][0] = b;
    for(int i = 0;i < a;++i){
        for(int j = 0;j <= i;++j){
            if(gl[i][j] >= (1 << i)){
                ans++;
                gl[i + 1][j] += gl[i][j] - (1 << i);
                gl[i + 1][j + 1] += gl[i][j] -(1 << i);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
