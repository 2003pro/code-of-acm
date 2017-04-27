#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int T,i,a;
    char str[14];
    scanf("%d",&T);
    getchar();
    while(T--){
        gets(str);
        a=strlen(str);
        if(a<=3){puts(str);}
        else if(a>3&&a<=6){for(i=0;i<a;i++){printf("%c",str[i]);if(a-i==4)printf(",");}printf("\n");}
        else if(a>6&&a<=9){for(i=0;i<a;i++){printf("%c",str[i]);if(a-i==4||a-i==7)printf(",");}printf("\n");}
        else if(a==10){for(i=0;i<a;i++){printf("%c",str[i]);if(a-i==4||a-i==7||a-i==10)printf(",");}printf("\n");}
    }
    return 0;
}
