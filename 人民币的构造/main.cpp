#include <iostream>
#include <cstdio>
#include  <cstring>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n==1||n==1) printf("1\n");
    else if(n==3||n==4) printf("2\n");
    else if(n>=5&&n<=13) printf("3\n");
    else if(n>=14&&n<=40) printf("4\n");
    else if(n>=41&&n<=121) printf("5\n");
    else if(n>=122&&n<=364) printf("6\n");
    else if(n>=365&&n<=1093) printf("7\n");
    else if(n>=1094&&n<=3280) printf("8\n");
    else if(n>=3281&&n<=9481) printf("9\n");
    else if(n>=9482&&n<=29524) printf("10\n");
    else if(n>=29524&&n<=100000) printf("11\n");
    return 0;
}
