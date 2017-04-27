#include <iostream>
#include <cstdio>
#include <cstring>


int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n == k) printf("1\n");
    else if(n%2 == 1) {
        if(k%2 == 0) printf("-1\n");
        else {
            if(n%k == 0 && (n/k) % 2 == 1) printf("%d\n",n/k);
            else if((n/k + 1) % 2 == 1) printf("%d\n",n/k + 1);
            else printf("%d\n",n/k + 2);
        }
    }
    else {
        if(k > n/2 && k < n - 1 && k%2 == 0) printf("3\n");
        else if(k > n/2 && k <= n - 1 && k%2 == 1) {
            if(n % (n - k) == 0 && (n/(n - k)) % 2 == 0) printf("%d\n",n/(n - k));
            else if((n/(n - k) + 1) % 2 == 0) printf("%d\n",n/(n - k) + 1);
            else printf("%d\n",n/(n - k) + 2);
        }
        else if(k <= n/2 && k % 2 ==0){
            if(n%k == 0) printf("%d\n",n/k);
            else printf("%d\n",n/k + 1);
        }
        else if(k <= n/2 && k % 2 == 1){
            if(n%k == 0 && n/k % 2 == 0) printf("%d\n",n/k);
            else if((n/k + 1) % 2 == 0) printf("%d\n",n/k + 1);
            else printf("%d\n",n/k + 2);
        }
    }
    return 0;
}
