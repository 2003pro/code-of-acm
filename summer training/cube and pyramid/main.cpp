#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int a,i,b,c;
    while(scanf("%d",&a)!=EOF){
        for(i=1;i<39;i++){
                b=i*(i+1)*(i+2)/6;
                c=abs(b-a);
                if (c<(i+2)*(i+1)/2){
                    printf("%d\n",i);
                    break;
                }
        }
    }
    return 0;
}
