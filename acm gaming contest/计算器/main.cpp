#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int str11[10003],t;
void calcu(int *p,int m,char st);
void mult(int *p,int m);
int main()
{
    cout << "请输入需要计算的式子,按回车键结束" << endl;
    char st;
    int len,i,m,j,str22[10003],k;
    memset(str11,0,sizeof(str11));
    memset(str22,0,sizeof(str22));
    string s;
    cin>>s;
    m=0;
    len=s.size();
    char *p=new char;
    s.copy(p,len,0);
    *(p+len)='\0';
    for(j=0;j<len;j++){
        if(*(p+j)=='+'){st='+';break;}
        else if(*(p+j)=='-'){st='-';break;}
        else if(*(p+j)=='*'){st='*';break;}
    }
    for(i=0;i<j;i++){
        str11[10002-j+i+1]=*(p+i)-'0';
    }
    t=j;
    for(i=j+1;i<len;i++){
        if(*(p+i)=='+'){
                if(t<m+1){t=m;}
                for(k=0;k<m;k++)str22[10002-m+k+1]+=(*(p+len-m+k)-'0');
                calcu(str22,m,st);
                m=-1;
                st='+';
                memset(str22,0,sizeof(str22));
        }
        else if(*(p+i)=='-'){
                if(t<m+1){t=m;}
                for(k=0;k<m;k++)str22[10002-m+k+1]+=(*(p+len-m+k)-'0');
                calcu(str22,m,st);
                m=-1;
                st='-';
                memset(str22,0,sizeof(str22));
        }
        else if(*(p+i)=='*'){
                if(t<m+1){t=m;}
                for(k=0;k<m;k++)str22[10002-m+k+1]+=(*(p+len-m+k)-'0');
                calcu(str22,m,st);
                m=-1;
                st='*';
                memset(str22,0,sizeof(str22));
        }
        m++;
    }
    if(t<m+1){t=m;}
    for(k=0;k<m;k++)str22[10002-m+k+1]+=(*(p+len-m+k)-'0');
    calcu(str22,m,st);
    if(str11[10002-t+1]==0)t--;
    for(i=10002-t+1;i<10003;i++)printf("%d",str11[i]);
    printf("\n");
    delete(p);
    return 0;
}
void calcu(int *p,int m,char st){
    int i,j;
    if(st=='*')   {
                    int i,j;
                    for(i=t;i>0;i++){
                    for(j=m;j>0;j++){
                    str11[10002-m+j-t+i]=p[10002-m+j]*str11[10002-t+i]+str11[10002-m+j-t+i];
                    str11[10002-m+j-t+i-1]+=str11[10002-m+j-t+i]/10;
                    str11[10002-m+j-t+i]%=10;
            }
        }
        t=t+m;
    }
    else {
            for(i=m;i>0;i--){
            if(st=='+') {str11[10002-m+i]+=p[10002-m+i];if(str11[10002-m+i]>9){str11[10001-m+i]++;str11[10002-m+i]%=10;}}
            else if(st=='-') {str11[10002-m+i]-=p[10002-m+i];if(str11[10002-m+i]<0){str11[10001-m+i]--;str11[10002-m+i]=10+str11[10002-m+i];}}
        }
    }
}
void mult(int *p,int m){
    int i,j;
    for(i=t;i>0;i++){
        for(j=m;j>0;j++){
                str11[10002-m+j-t+i]=p[10002-m+j]*str11[10002-t+i]+str11[10002-m+j-t+i];
                str11[10002-m+j-t+i-1]+=str11[10002-m+j-t+i]/10;
                str11[10002-m+j-t+i]%=10;
        }
    }
}
