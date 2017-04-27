#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void add(int *a,int *b);
void sub(int *a,int *b);
void mult(int *a,int *b);
int len1,len2,d1,d2;
int main()
{
    string s1,s2;
    int a[103],b[103],i;
    char c;
    cout << "请输入需要计算的第一个数,回车结束" << endl;
    cin>>s1;
    cout << "请输入需要进行的运算,回车结束" << endl;
    cin>>c;
    cout << "请输入需要计算的第二个数,回车结束" << endl;
    cin>>s2;
    if(s1[0]=='-') {d1=-1;s1.erase(0,1);}
    else d1=1;
    if(s2[0]=='-') {d2=-1;s2.erase(0,1);}
    else d2=1;
    len2=s2.size();
    len1=s1.size();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=0;i<s1.size();i++) a[i]=s1[i]-'0';
    for(i=0;i<s2.size();i++) b[i]=s2[i]-'0';
    if(c=='+'){add(a,b);}
    else if(c=='-'){sub(a,b);}
    else if(c=='*'){mult(a,b);}
    return 0;
}
void add(int *a,int *b){
    int c[203],i,d;
    memset(c,0,sizeof(c));
    d=max(len1,len2);
    if(d1*d2>0){
        for(i=0;i<d;i++){
            c[i]+=a[i]+b[i];
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
        }
        if(d1<0)printf("-");
        if(!c[d+1])d++;
        for(i=d-1;i>=0;i--)printf("%d",c[i]);
        printf("\n");
    }
    else if(d2<0) {d2=1;sub(a,b);}
    else if(d1<0) {d1=1;sub(b,a);}
}
void sub(int *a,int *b){
    int c[203],i,d;
    memset(c,0,sizeof(c));
    d=max(len1,len2);
    if(d2<0){d2=1;add(a,b);}
    if(d1<0){printf("-");d1=1;add(a,b);}
    else if(d1<0)
    for(i=0;i<d;i++){
            if(a[i]<b[i]){
                a[i+1]--;
                a[i]+=10;
            }
            c[i]=a[i]-b[i];
    }
    while (!c[d-1]) d--;
    for(i=d-1;i>=0;i--)printf("%d",c[i]);
    printf("\n");
}
void mult(int *a,int *b){
    int c[10003],i,d,j;
    memset(c,0,sizeof(c));
    d=len1*len2;
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]=c[i+j]%10;
        }
    }
    if(d1*d2<0)printf("-");
    if (!c[d-1]) d--;
    for(i=d-1;i>=0;i--)printf("%d",c[i]);
    printf("\n");
}
