#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

long long  calcu();
long long  uni();
int judge(char c);
char str[1000003];
stack<int> t;
stack<long long> number;
stack<char> opera;

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        gets(str);
        printf("%lld\n",calcu());
    }
}

long long calcu(){
    long long  sum = 0,i = 0;
    for(i=0;str[i]!='\0';i++){
        number.push(0);
        if(str[i]>='0'&&str[i]<='9') t.push(str[i]-'0');
        else if(str[i] == ' ') continue;
        else {
            opera.push(str[i]);
            number.push(uni());
            break;
        }
    }
    for(i++;str[i]!='\0';i++){
        if(str[i]>='0'&&str[i]<='9') t.push(str[i]-'0');
        else if(str[i] == ' ') continue;
        else {
            char c = opera.top();
            opera.push(str[i]);
            if(!t.empty())number.push(uni());
            if(judge(c) == 1){
                for(i++;str[i]>='0'&&str[i]<='9';i++) t.push(str[i]-'0');
                char d = opera.top();
                opera.pop();
                sum = uni();
                long long a = number.top();
                number.pop();
                if(d == '*') sum *= a;
                else if(d == '/') sum = a/sum;
                number.push(sum);
//                printf("%d   s\n",sum);
                i--;
            }// 新入运算优先级高于原有运算
            else {
                char t1 = opera.top();
                opera.pop();
                char d = opera.top();
                opera.pop();
                sum = number.top();
                number.pop();
                long long  a = number.top();
                number.pop();
                if(d == '*') sum *= a;
                else if(d == '/') sum = a/sum;
                else if(d == '+') sum = sum +a;
                else if(d == '-') sum = a - sum;
                number.push(sum);
                opera.push(t1);
//                printf("%d   s\n",sum);
            }
        }// 新入运算优先级低于或等于原有运算
    }
    if(!t.empty())number.push(uni());
    char t2 = opera.top();
    sum = number.top();
    number.pop();
    long long  a1 = number.top();
    number.pop();
    if(t2 == '*') sum = sum*a1;
    else if(t2 == '/') sum = a1/sum;
    else if(t2 == '+') sum = a1+ sum;
    else if(t2 == '-') sum = a1 - sum;
    return sum;
}

long long uni(){
    long long sum = 0,t1,temp,i;
    int s = t.size();
    int t2 = s;
    while(!t.empty()){
        i = t2 - s;
        temp = 1;
        t1 = t.top();
        t.pop();
        while(i--) temp *= 10;
        sum += t1*temp;
        s--;
    }
//    printf("%d 3\n",sum);
    return sum;
}

int judge(char c){
    char d = opera.top();
//    printf("%c   2  %c\n",d,c);
    int a=0,b=0;
    if(c=='*'||c=='/') a = 1;
    if(d=='*'||d=='/') b = 1;
    if(a==b) return 0;
    else if(a < b) return 1;
    else if(a > b) return -1;
}
