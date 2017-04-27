#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,flag = 0;char t;
    scanf("%d %d",&n,&m);
    while(n--){
        int i = m;
        while(i--){
            cin>>t;
            if(t =='C'||t == 'M'||t == 'Y') flag = 1;
        }
    }
    if(flag) printf("#Color\n");
    else printf("#Black&White\n");
    return 0;
}
