#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char str[1000063];
int p[50];
stack<long long> number;
stack<char> opera;

long long cal(long long x,long long y,char c){
    if(c == '+') return x+y;
    else if(c == '-') return x-y;
    else if(c == '*') return x*y;
    else if(c == '/') return x/y;
}

long long calcu(){
    long long temp =0;
    long long x,y;
    int i,t;
    opera.push('&');
    str[0] = '0';
    str[strlen(str)] = '!';
    int n=strlen(str);
    for(i = 0; i<n ;i++){
        if(isdigit(str[i])){
            t = str[i] - '0';
            temp = temp*10 + t;
        }
        else {
            number.push(temp);
            temp = 0;
            while(p[str[i]] <= p[opera.top()]){
                x = number.top();number.pop();
                y = number.top();number.pop();
                char c =opera.top(); opera.pop();
                number.push(cal(y,x,c));
            }
            opera.push(str[i]);
        }
    }
    return number.top();
}


int main()
{
    p['&'] = 0;
    p['!'] = 1;
    p['+'] = p['-'] = 2;
    p['*'] = p['/'] = 3;
    int T;
    scanf("%d",&T);
    while(T--){
        while(!number.empty()) number.pop();
        while(!opera.empty()) opera.pop();
        memset(str,0,sizeof(str));
        scanf("%s",str+1);
        printf("%lld\n",calcu());
    }
}
