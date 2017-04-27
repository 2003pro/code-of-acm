#include <bits/stdc++.h>
int main(){
    int n,t,f = 1;scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&t);
        if(t == 1) {printf("%d\n",f+1);continue;}
        else if(t%2 == 0) f = !f;
        else if(t%2 == 1) f = f;
        printf("%d\n",f+1);
    }
}
