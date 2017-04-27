#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int solve(char *str,int n);
int mi(int a,int n);
int bit[64];


int main()
{
    int n,i,num,s;char str[66];
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        getchar();
        gets(str);
        scanf("%d",&num);
        s=solve(str,n);
    }
    if(s<=)
    return 0;
}
int mi(int a,int n){
    int i,sum=1;
    for(i=0;i<n;i++){
        sum*=2;
    }
    return sum;
}

int solve(char *str,int n){
    int i,m=0,sum=0;
    for(i=n-1;i>=0;i--){
        if(str[i]=='n') bit[m]=0;
        else if(str[i]=='p') bit[m]=1;
        m++;
        sum+=mi(2,m)*bit[m];
    }
    return sum;
}
