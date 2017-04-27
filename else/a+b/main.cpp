#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    char str[100];
    stack<int> t;
    gets(str);
    for(int i=0;i<3;i++) t.push(str[i]);
    int sum = 0,t1,temp;
    int s = t.size();
    int i = s;
    while(!t.empty()){
        i = i - s;
        temp = 1;
        t1 = t.top();
        t.pop();
        while(i--) temp *= 10;
        sum += t1*temp;
        s--;
    }
    printf("%d\n",sum);
}
