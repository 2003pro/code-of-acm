#include <bits/stdc++.h>
int a[300003];
int main(){
    int n,q,x,y,sum = 0;scanf("%d %d",&n,&q);
    for(int i = 0;i < q;i++){
        scanf("%d%d",&x,&y);
        if(x == 1) {a[y]++;sum++;printf("%d\n",sum);}
        if(x == 2) {a[y] = 0;sum -= a[y];printf("%d\n",sum);}
        if(x == 3) {}
    }
}
