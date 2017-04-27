#include <bits/stdc++.h>

using namespace std;

const int N = 25600000;
bool a[N];
int p[N];
int n1 = 2000000,num;

void Prime1() {
    memset(a, 0, n1 * sizeof a[0]);
    int i, j;
    for(i = 2; i < n1; ++i) if(!a[i]) {
        p[num++] = i;
        for(j = i+i; j < n1; j +=i) {
            a[j] = 1;
        }
    }

}
int main()
{
    int n,m;
    Prime1();
    scanf("%d",&n);
    if(n == 1) printf("3\n");
    else if(n == 2) printf("4\n");
    else if(n&1) printf("1\n");
    else {
        int t = 2;
        while(1){
            m = t*n+1;
            if(a[m]) break;
            t++;
        }
        printf("%d\n",t);
    }
    return 0;
}
