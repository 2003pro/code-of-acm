#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int calcu(int n){
    if(n%3 != 0)  return 2*(n/3)+1;
    else return 2*(n/3);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",calcu(n));
    return 0;
}
