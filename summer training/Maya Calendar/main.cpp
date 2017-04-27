#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
char s1[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char s2[20][9]={"imix", "ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok", "chuen","eb", "ben","ix","mem","cib","caban","eznab","canac","ahau"};
string cal[10000];
int date;
int solve(string s);
void out(int i);

int main()
{
    char str[20];
    int T,i;scanf("%d",&T);getchar();
    printf("%d\n",T);
    for(i=0;i<T;i++){
        fgets(str,20,stdin);
        cal[i]=str;
        date=solve(cal[i]);
        out(date);
    }
    return 0;
}
int solve(string s){
    char month[7];int day=0;int year=0;int month1=0;
    int i=0,m;
    for(;s[i]!='.';i++){day=day*10+(s[i]-'0');}m=i+2;
    for(i=i+2;s[i]!=' ';i++){month[i-m]=s[i];}month[i-m]='\0';
    for(++i;s[i]>='0'&&s[i]<='9';i++){year=year*10+(s[i]-'0');}
    for(i=0;i<19;i++){if(strcmp(month,s1[i])==0){month1=i;break;}}
    day=day+month1*20+year*365;
    return day;
}
void out(int i){
    int a,b,c;
    a=i/260;
    b=i%20;
    c=i%13+1;
    printf("%d %s %d\n",c,s2[b],a);
}
