#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
bool isLeap(int n){
    if(n%100==0&&n%400!=0) return false;
    else if(n%4==0) return true;
    else return false;
}

int main()
{
    int n,s = 0;
    scanf("%d",&n);
    int n1 = n;
    while(!isLeap(n1)){
        n1--;
        s++;
    }
    if(s==0) printf("%d\n",n+28);
    else if(s==1) printf("%d\n",n+6);
    else if(s==2) printf("%d\n",n+11);
    else if(s==3) printf("%d\n",n+11);
    return 0;
}
