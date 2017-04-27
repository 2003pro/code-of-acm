#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long b,d,s;
    scanf("%I64d%I64d%I64d",&b,&d,&s);
    long long mi = min(b,d); mi = min(mi,s);
    b -= mi,d -= mi,s -= mi;
    if(!b + !d +!s == 2) printf("%I64d\n",2*(b+d+s-1));
    else if(!b + !d +!s == 3) printf("0\n");
    else {
        if(b && d){
            if(b == d) printf("%I64d\n",b-1);
            else printf("%I64d\n",2*(abs(b-d)-1)+min(b,d));
        }
        else if(b && s){
            if(b == s) printf("%I64d\n",b-1);
            else printf("%I64d\n",2*(abs(b-s)-1)+min(b,s));
        }
        else{
            if(s == d) printf("%I64d\n",s-1);
            else printf("%I64d\n",2*(abs(s-d)-1)+min(s,d));
        }
    }
    return 0;
}
