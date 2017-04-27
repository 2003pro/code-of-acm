#include <bits/stdc++.h>
#define out freopen("out.txt","w",stdout)
using namespace std;
const int N = 3e6+7;
int s1[N],s2[N],n;
int main(){
    out;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        s1[i] = rand()%2;
        s2[i] = rand()%2;
    }
    for(int i = 0;i < n;i++) printf("%d",s1[i]); printf("\n");
    for(int i = 0;i < n;i++) printf("%d",s2[i]); printf("\n");
}
