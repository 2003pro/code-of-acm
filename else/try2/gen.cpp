#include <bits/stdc++.h>
#define out freopen("out.txt","w",stdout)
using namespace std;
const int N = 100003;
int a,s1[N];
char s[N];
int main(){
    out;
    scanf("%d",&a);
    for(int i = 0;i < a;i++){
        if(rand()%2 == 1) s[i] = '>';
        else s[i] = '<';
        s1[i] = rand()%a;
    }
    printf("%d\n",a);
    for(int i = 0;i < a;i++) printf("%c",s[i]); printf("\n");
    for(int i = 0;i < a;i++) printf("%d ",s1[i]);
}
