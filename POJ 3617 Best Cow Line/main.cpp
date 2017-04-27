#include <iostream>
#include <cstdio>
#include <cstring>
#define ini(x,y) memset(x,y,sizeof(x));

using namespace std;
int n;
char s[2003];

int main()
{
    scanf("%d",&n);
    int cnt = 0;
    for(int i = 0;i < n;i++) {getchar();scanf("%c",&s[i]);}
    int a = 0,b = n-1;
    while(a <= b){
        bool left = false;
        for(int i = 0;a+i<=b;i++){
            if(s[a+i]<s[b-i]){left = true;break;}
            else if(s[a+i]> s[b-i]){left = false;break;}
        }
        if(left) putchar(s[a++]);
        else putchar(s[b--]);cnt++;
        if(cnt%80 == 0) printf("\n");
    }
    return 0;
}
