#include <bits/stdc++.h>
#define iOS ios_base::sync_with_stdio(false)
using namespace std;

int main()
{
    iOS;int n;
    cin>>n;
    if(n <= 3)printf("NO\n");
    else {
        printf("YES\n");
        int s = n%4,s1 = n/4;
        if(s == 0){
            printf("1 * 2 = 2\n3 * 4 = 12\n2 * 12 = 24\n");
            for(int i = 1;i < s1;i++){
                printf("%d - %d = -1\n",i*4+1,i*4+2);
                printf("%d - %d = 1\n",i*4+4,i*4+3);
                printf("1 + -1 = 0\n24 + 0 = 24\n");
            }
        }
        else if(s == 1){
            printf("4 * 5 = 20\n3 - 1 = 2\n2 + 2 = 4\n20 + 4 = 24\n");
            for(int i = 1;i < s1;i++){
                printf("%d - %d = -1\n",i*4+2,i*4+3);
                printf("%d - %d = 1\n",i*4+5,i*4+4);
                printf("1 + -1 = 0\n24 + 0 = 24\n");
            }
        }
        else if(s == 2){
            printf("5 * 6 = 30\n2 * 4 = 8\n30 - 8 = 22\n3 - 1 = 2\n22 + 2 = 24\n");
            for(int i = 1;i < s1;i++){
                printf("%d - %d = -1\n",i*4+3,i*4+4);
                printf("%d - %d = 1\n",i*4+6,i*4+5);
                printf("1 + -1 = 0\n24 + 0 = 24\n");
            }
        }
        else {
            printf("6 * 7 = 42\n4 * 5 = 20\n42 - 20 = 22\n3 - 2 = 1\n22 + 1 = 23\n23 + 1 = 24\n");
            for(int i = 1;i < s1;i++){
                printf("%d - %d = -1\n",i*4+4,i*4+5);
                printf("%d - %d = 1\n",i*4+7,i*4+6);
                printf("1 + -1 = 0\n24 + 0 = 24\n");
            }
        }
    }
    return 0;
}
