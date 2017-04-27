#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
priority_queue<int>  s1;
priority_queue<int>  s2;
priority_queue<int>  s3;
int T,dp1[500003],dp2[500003];

void CalDp1(int*  a){
    int temp = 0;
    dp1[1] = a[1];
    for(int i = 2;i <= T;i++){
        temp = a[i] + dp1[i - 1];
        if(a[i] > temp) dp1[i] = a[i];
        else dp1[i] = temp;
    }
    for(int i = 2 ;i <= T;i++){
        dp1[i] = max(dp1[i-1],dp1[i]);
    }
}

void CalDp2(int* a){
    int temp = 0;
    dp2[T] = a[T];
    for(int i = T-1;i >= 1;i--){
        temp = a[i] + dp2[i + 1];
        if(a[i] > temp) dp2[i] = a[i];
        else dp2[i] = temp;
    }
    for(int i = T-1;i>=1;i--){
        dp2[i] = max(dp2[i],dp2[i+1]);
    }
}

int CalAns(){
    int temp1,temp2;
    for(int i =2;i < T;i++){
        s3.push(dp1[i-1]+dp2[i+1]);
    }
    return s3.top();
}

int main()
{
    int a[500003];
    memset(a,0,sizeof(a));
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    scanf("%d",&T);
    for(int i = 1 ;i <=T;i++){
        scanf("%d",&a[i]);
    }
    CalDp1(a);
    CalDp2(a);
    printf("%d\n",CalAns());
    return 0;
}
