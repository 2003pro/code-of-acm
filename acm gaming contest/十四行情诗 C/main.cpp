#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[1001];
int s1[1001];
void bubblesort(int l){
    int t;
    for(int i = 0;i < l;i++){
        for(int j = i;j < l;j++){
            if(s1[i] >= s1[j]){
                t = s1[j];
                s1[j] = s1[i];
                s1[i] = t;
            }
        }
    }
}
int main()
{
    scanf("%s",s);
    int l = strlen(s);
    for(int i = 0;i < l;i++) s1[i] = s[i] - '0';
    bubblesort(l);
    for(int i = 0;i < l;i++) printf("%d",s1[i]);printf("\n");
    return 0;
}
