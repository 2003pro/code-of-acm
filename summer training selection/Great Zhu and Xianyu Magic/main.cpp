#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 5003;

int Knapsack(int a,int b,int w[],int v[]){
    int c[N];
    memset(c,0,sizeof(c));
    for(int i =1;i <= b;i++){
        for(int j = a;j >= w[i];j--){
            if(c[j] <= v[i] + c[j - w[i]]) c[j] = v[i] + c[j - w[i]];
        }
    }
    return c[a];
}

int main()
{
    int w[N],v[N],a,b;
    scanf("%d%d",&a,&b);
    for(int i = 1;i <= b;i++) scanf("%d%d",&w[i],&v[i]);
    printf("%d\n",Knapsack(a,b,w,v));
    return 0;
}
