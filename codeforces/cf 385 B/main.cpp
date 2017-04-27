#include <bits/stdc++.h>

using namespace std;
char s[501][501];
int c[501][501];
int n,m;
int check(int i,int j){
    int ans = 0;
    if(s[i-1][j] == '.' || i-1 < 0 ) ans++;
    if(s[i][j-1] == '.' || j-1 < 0 ) ans++;
    if(s[i+1][j] == '.' || i+1 >= n ) ans++;
    if(s[i][j+1] == '.' || j+1 >= m ) ans++;
    return ans;
}
typedef pair<int,int> pii;
int main()
{
    scanf("%d%d",&n,&m);
    pii a[2];
    a[0].first = 0;
    a[1].first = 0;
    for(int i = 0;i < n;i++){
        scanf("%s",s[i]);
    }
    int ll = 0,flag = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
//            if(s[i][j] == 'X' )c[i][j] = check(i,j);
            if(s[i][j] == 'X' && flag) {
                if(check(i,j) == 4) flag = 0;
                if(check(i,j) == 3 && ll <= 2) {
                    a[ll].first = i,a[ll].second = j;
                    ll++;
                }
                else if(check(i,j) == 3){
                    printf("NO\n");
                    return 0;
                }
            }
            else if(s[i][j] == 'X' && !flag){
                printf("NO\n");
                return 0;
            }
        }
    }
//    for(int i = 0;i < n;i++){
//        for(int j = 0;j < m;j++){
//            printf("%d",c[i][j]);
//        }
//        printf("\n");
//    }
    if(!flag) {
        printf("YES\n");
        return 0;
    }
    else if(a[0].first != a[1].first && a[0].second != a[1].second) {
        printf("NO\n");
        return 0;
    }
    else printf("YES\n");
//    printf("%d %d %d %d",a[0].first,a[0].second,a[1].first,a[1].second);
    return 0;
}
