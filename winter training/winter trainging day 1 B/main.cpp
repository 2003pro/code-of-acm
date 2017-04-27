#include <bits/stdc++.h>

using namespace std;
int mp[10] = {6,2,5,5,4,5,6,3,7,6};
int mp1[10] = {9,1,5,5,4,5,9,7,8,9};
int mp2[8] = {0,0,1,7,4,5,9,8};
int a[100005];
char s[100005];
int cmp(int a,int b){
    return a > b ? 1:0;
}
int main()
{
    int T,n,t;scanf("%d",&T);
    while(T--){
        int sum = 0;
        scanf("%d",&n);
        int cn = n;
        scanf("%s",s);
        if(n == 1) {
            t = s[0] - '0';
            printf("%d\n",mp1[t]);
            continue;
        }
        for(int i = 0;i < cn;i++) {
            t = s[i] - '0';
//            printf("%d ",mp[t]);
            a[i] = mp[t];
            sum += mp[t];
        }
//        printf("%d\n",sum);
        if(sum <= cn*6){
            sum -= cn*2;
//            sort(a,a+n,cmp);
//            for(int i = 0;i < n;i++) printf("%d",a[i]);printf("\n");
            for(int i = 0;i < cn-1;i++){
                if(sum >= 4) {a[i] = mp2[6];sum -= 4;}
                else if(sum > 0 && sum < 4){a[i] = mp2[3];sum -= 1;}
                else a[i] = mp2[2];
            }
            if(sum == 0) a[cn-1] = mp2[2];
            else a[cn-1] = mp2[(2+sum)];
        }
        else {
            int l = sum - cn*6;
            int j = cn-1;
            while(l > 0){
                a[j--] = 8;
                l--;
            }
            for(int i = 0;i <= j;i++) a[i] = 9;
        }
        for(int i = 0;i < cn;i++) printf("%d",a[i]);printf("\n");
    }
    return 0;
}
