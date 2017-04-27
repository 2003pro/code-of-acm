#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
    int p[101],n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&p[i]);
    }
    int c = std::max(n - m + 1,m);
    int sum = p[m];
    for(int i = 1;i < c;i++){
        if(m - i >= 1 && m + i <= n){
            if(p[m - i] > 0 && p[m + i] > 0) sum += 2;
        }
        else if(m - i >= 1 && m + i > n){
            if(p[m - i] > 0) sum++;
        }
        else if(m - i < 1 && m + i <= n){
            if(p[m + i] > 0) sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}
