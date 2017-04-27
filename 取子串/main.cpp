#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[101];
bool getstr(int a,int b);

int main()
{
    int i,b,c,l;
    gets(str);
    scanf("%d",&l);
    for(i=0;i<l;i++){
        scanf("%d %d",&b,&c);
        getstr(b,c);
    }
    return 0;
}
bool getstr(int a,int b){
    int i,c;
    c=strlen(str);
    for(i=a;i<b+a;i++){
        if(i>=c) break;
        printf("%c",str[i]);
    }
    printf("\n");
    return true;
}

