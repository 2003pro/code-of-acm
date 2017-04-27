#include <iostream>
#include <cstdio>
#include <stack>
#include <deque>
using namespace std;

int main()
{
    stack<int> s;
    int t,n,m,a[10000],s1=1,s2=1,s3=1,t1,t2;
    scanf("%d",&m);
    scanf("%d%d",&a[0],&a[1]);
    for(int i=2;i<m;i++){
        for(int j=0;j<i+1;j++){
            t=a[i]+a[j];
            for(int k=0;k<i+1;k++)if(t==a[k])s1--;
            if(s1)s.push(t);
        }

    }
    while(!s.empty()) {cout<<s.top()<<" "; s.pop();}
}
