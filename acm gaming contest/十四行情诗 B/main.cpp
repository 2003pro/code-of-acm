#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[103];
int s1[6];
int check(){
    for(int i = 0;i < 6;i++){
        if(s1[i] >= 50) return i;
    }
    return -1;
}
int main()
{
    int n,k,t,l;
    scanf("%d%d",&n,&k);
    if(n < k){
        for(int i = 0;i < n;i++){
            memset(s,0,sizeof(s));
            scanf("%s",s);
            l = strlen(s);
            for(int j = 0;j < l;j++){
                t = s[j] - 'A';
                s1[t]++;
                t = check();
                if(t != -1) {
                    printf("%d %c\n",i+1,'A'+check());
                    return 0;
                }
            }
            s1[5]++;
        }
        printf("AMNZ\n");
    }
    else if(n >= k){
        for(int i = 0;i < k;i++){
            scanf("%s",s);
            l = strlen(s);
            for(int j = 0;j < l;j++){
                t = s[j] - 'A';
                s1[t]++;
                t = check();
                if(t != -1) {
                    printf("%d %c\n",i+1,'A'+check());
                    return 0;
                }
            }
            s1[5]++;
        }
        printf("Feizhou Yin\n");
    }
    return 0;
}
