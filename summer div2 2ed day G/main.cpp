#include <bits/stdc++.h>


int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        bool f = true;
        char s[53];
        scanf("%s",s);
        int l = strlen(s);
        for(int i = 0;i < l;i++)
            if(s[i] == 'D') {f = false;break;}
        if(f) printf("Possible\n");
        else printf("You shall not pass!\n");
    }
    return 0;
}
