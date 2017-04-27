#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int a,b,c[30003],i,s;
    while (scanf("%d%d",&a,&b)!=EOF){
        i=0;
        for(i=1;i<a;i++) scanf("%d",&c[i]);
        s=1+c[1];
        i=0;
        while(i<a-1){
            if(s==b) { printf("YES\n");break;}
            else if(s>b) break;
            s=s+c[s];
            i++;
        }
        if(s!=b)  printf("NO\n");
    }
    return 0;
}
