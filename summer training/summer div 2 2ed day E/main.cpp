#include <bits/stdc++.h>

using namespace std;
int cnt = 0,p[1003],s[1400];
bool isf(int l){
    int cot = 0;
    for(int i = 0;i < cnt &&l >p[i];i++){
        if(l%p[i] == 0) cot++;
        if(cot >= 3) return true;
    }
    return false;
}
int main()
{
    int f[1000];
    memset(f,0,sizeof(f));
    for(int i = 2;i < 550;i++){
        if(!f[i]) p[cnt++] = i;
        for(int j = 0;j < cnt &&p[j]*i< 550;j++){
            f[i*p[j]] = 1;
            if(i%p[j] == 0) break;
        }
    }
    int k = 1;
    for(int i = 0;i < 2700;i++){
        if(isf(i)) {s[k] = i;k++;}
    }
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",s[n]);
    }
    return 0;
}
