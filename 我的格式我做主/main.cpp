#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a,b,c,d,i;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        getchar();
        while(a--){
                char str[85],str1[43],str2[43],m[85];
                gets(str);
                int f;
                int e=strlen(str);
                for(i=0;i<e;i++){if(str[i]==' ')f=i;}
                for(i=0;i<f;i++){str1[i]=str[i];}
                str1[f]='\0';
                for(i++;i<e;i++){str2[i-f-1]=str[i];}
                str2[e-f]='\0';
                if(d!=0){printf("%*s %*s",b,str1,c,str2);printf("\n");}
                else {printf("%s %s",str1,str2);printf("\n");}
        }
    }
    return 0;
}
