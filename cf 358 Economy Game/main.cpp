#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int gcd(int a,int b){
    return b==0?a:a%b;
}

int ngcd(int *a, int n){
    if (n == 1)  return *a;
    return gcd(a[n-1], ngcd(a, n-1));
}

int main()
{
    int a[3];a[0] = 1234567,a[1] = 123456;a[2] = 1234;
    printf("%d\n",ngcd(a,3));
    return 0;
}
