#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
pii lr[1005];
int a,b,st[1005];
char s[1005];
int main()
{
    int n,l,t = 0;
    while(scanf("%d",&n) != EOF){
        if(!n) break;
        memset(st,0,sizeof(st));
        scanf("%s",s);int l1 = strlen(s),cnt = 0,sum = 0;
        s[l1] = ',';l = 0;t = 0;
        for(int i = 0;i <= l1;i++){
            if(s[i] == '-'){
                l = t;
                t = 0;
            }
            else if(s[i] == ','){
                pii t1;t1.first = l;t1.second = t;
                if (l == 0) {t1.first = t1.second = t;lr[cnt++] = t1;}
                else if(l <= t)lr[cnt++] = t1;
                l = 0;t = 0;
            }
            else {
                t = t*10 + s[i]-'0';
                t = min(1005,t);
            }
        }
        for(int i = 0;i < cnt;i++){
//            printf("%d %d ",lr[i].first,lr[i].second);
            for(int j = lr[i].first;j <= lr[i].second;j++)
                st[j] = 1;
        }
        for(int i = 1;i <= n;i++){
            sum += st[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
