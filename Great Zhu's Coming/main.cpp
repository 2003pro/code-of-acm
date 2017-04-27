#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct node{
    int x, y,wei;
    friend bool operator <(node a,node b){
        return a.wei > b.wei;
    }
};

priority_queue <node> s;

int dp[203];

int min1(int a,int b,int c){
    int d= min(a,b);
    return min(d,c);
}

int solve(int a,int b,int c){
    int t1=0,t2=0;
    dp[0] = 0,dp[1] = 1,dp[2] = 1;
    if(b != 2) dp[2] = 2;
    int sum = dp[0]+dp[1]+dp[2];
    for(int i = 3;i <= a;i++){
        if(i - b < 0) t1 = 100000;
        else t1 = dp[i - b];
        if(i - c < 0) t2 = 100000;
        else t2 = dp[i - c];
        dp[i] = min1(dp[i-1],t1,t2)+1;
        sum += dp[i];
    }
    return sum;
}

int main()
{
    int T,a;
    scanf("%d",&T);
    while(T--){
        while(!s.empty()) s.pop();
        scanf("%d",&a);
        if(a <= 6) printf("1 2 3\n");
        else {
            for(int i = 2;i < a/2 && i <=20;i++){
                for(int j = i + 1;j <= a && j <=35;j++){
                    node a1;
                    a1.wei = solve(a,i,j);
                    a1.x = i;
                    a1.y = j;
                    s.push(a1);
                }
            }
            node b1 = s.top();
            printf("1 %d %d\n",b1.x,b1.y);
        }
    }
    return 0;
}
