#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int T,i,l,m;
    char str[201];
    scanf("%d\n",&T);
    while(T--){
        gets(str);
        m=1;
        l=strlen(str);
        for(i=0;i<l;i++){
            if(str[i]==' '&&str[i-1]!=' ') m++;
        }
        if(str[0]==' ') m--;
        if(str[l-1]==' ') m--;
        printf("%d\n",m);
    }
    return 0;
}
