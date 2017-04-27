#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int f[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int a[17],b[17],c[17],n,m,ans1 = 10000,ans2 = 10000;
bool judge(){
    int l = 0,l1 = 0;
    for(int i = 0;i < n;i++) l += a[i]*f[i],l1 += c[i]*f[i];
    if(l == l1)return true;
    else return false;
}
int sear(int i,int w){
    for(int j = i;j < n;j++){
        if(c[j] == w) return j;
    }
}

void sw(int x,int y){
    int t = c[x];
    c[x] = c[y];
    c[y] = t;
}

int main()
{
    ini(a,0);ini(b,0);ini(c,0);
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    for(int i = 0;i < m;i++) scanf("%d",&b[i]);
    int l = 0;
    for(int i = 0;i < m;i++){
        int l1 = l + b[i];
        int t = i % 2;
        for(int j = l;j < l1;j++){
            c[j] = t;
        }
        l = l1;
    }
//    for(int i = 0;i < n;i++) printf("%d ",c[i]);
//    printf("\n");
    if(judge()) {printf("0\n");return 0;}
    if(!judge() && count(a,a+n,1) == count(c,c+n,1)){
        ans1 = 0;
        for(int i = 0;i < n;i++){
            if(a[i]!=c[i]){
                int j = sear(i,a[i]) - i;
                ans1 += j;
                sw(i,i+j);
            }
        }
    }
    //----
    l = 0;
    for(int i = 0;i < m;i++){
        int l1 = l + b[i];
        int t = (i+1) % 2;
        for(int j = l;j < l1;j++){
            c[j] = t;
        }
        l = l1;
    }
//    for(int i = 0;i < n;i++) printf("%d ",c[i]);
//    printf("\n");
    if(judge()) {printf("0\n");return 0;}
    if(!judge() && count(a,a+n,1) == count(c,c+n,1)){
        ans2 = 0;
        for(int i = 0;i < n;i++){
            if(a[i]!=c[i]){
                int j = sear(i,a[i]) - i;
//                printf("%d * ",j);
                ans2 += j;
                sw(i,i+j);
            }
        }
    }
    printf("%d\n",min(ans1,ans2));
    return 0;
}
