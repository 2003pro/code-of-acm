#include <bits/stdc++.h>


int main(){
    int m = 0,c = 0,n,x,y;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&x,&y);
        if(x > y) m++;
        else if(x < y) c++;
    }
    if(m > c)printf("Mishka\n");
    else if(m < c) printf("Chris\n");
    else printf("Friendship is magic!^^\n");
}
