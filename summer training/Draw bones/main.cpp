#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    int a = 0;
    int n[2003];
    n[1] = 1;n[2] = 2;n[3] = 3;n[4] = 4; n[5] = 5;
    for(int i = 6;i <= 2000;i++){
        if(i%2 == 0) {
            n[i] = n[i/2] + 2;
            if(n[i] < n[i - 2]) n[i - 1] = n[i] + 1;
        }
        else n[i] = n[i - 1] + 1;
    }
    while(scanf("%d",&a) != EOF){
        printf("%d\n",n[a]);
    }
    return 0;
}
