#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int n;
int cnt = 1,p[1003],b[9],a[9];
int main()
{
    p[0] = 1;
    int f[1000];
    memset(f,0,sizeof(f));
    for(int i = 2;i < 550;i++){
        if(!f[i]) p[cnt++] = i;
        for(int j = 1;j < cnt &&p[j]*i< 550;j++){
            f[i*p[j]] = 1;
            if(i%p[j] == 0) break;
        }
    }
    while(scanf("%d",&n) != EOF && n){
        printf("%d = ",n);
        int j = 0,k;
        while(n > 0){
            k = n%p[j];n/=p[j];
            if(k > 0){
                printf("%d",k);
                for(int i = 1;i < j;i++) printf("*%d",p[i]);
                if(n == 0) printf("\n");
                else printf(" + ");
            }
            j++;
        }
    }
    return 0;
}
