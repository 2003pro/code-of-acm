#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d",&n);
    printf("I hate ");
    for(int i = 2;i <= n;i++){
        if(i%2 == 0)printf("that I love ");
        if(i%2 == 1)printf("that I hate ");
    }
    printf("it\n");
}
