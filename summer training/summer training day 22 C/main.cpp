#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N = 100003;
char a[N];
int s1[N];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        ini(s1,0);
        int sl,st,sum = 0,max1 = 0,furi;scanf("%d %d",&sl,&st);furi = st;
        scanf("%s",a+1);
        if(st <= sl/2){
            for(int i = 1;i <= sl/2;i++){
                if(a[i] != a[sl-i+1]) {
                    sum += min(abs(a[i] - a[sl-i+1]),26 - abs(a[i] - a[sl-i+1]));
                    s1[i] = abs(i-st);
                    if(s1[i] > max1) max1 = s1[i],furi = i;
                }
            }
            if(furi > st){
                for(int i = 1;i < st;i++) if(s1[i] != 0) {sum += (furi - i - 1);break;}
            }
            else if(furi < st){
                for(int i = sl/2;i > st;i--) if(s1[i] != 0){sum += (i - furi - 1);break;}
            }
            printf("%d\n",sum+max1);
        }
        else {
            for(int i = 1;i <= sl/2;i++){
                if(a[i] != a[sl-i+1]) {
                    sum += min(abs(a[i] - a[sl-i+1]),26 - abs(a[i] - a[sl-i+1]));
                    s1[sl-i+1] = abs(sl-i+1-st);
                    if(s1[sl-i+1] > max1) max1 = s1[sl-i+1],furi = sl-i+1;
                }
            }
            if(furi > st){
                for(int i = sl/2;i < st;i++) if(s1[i] != 0) {sum += (furi - i - 1);break;}
            }
            else if(furi < st){
                for(int i = sl;i > st;i--) if(s1[i] != 0){sum += (i - furi - 1);break;}
            }
            printf("%d\n",sum+max1);
        }
    }
    return 0;
}
