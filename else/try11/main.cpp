#include <bits/stdc++.h>

const int S = 8;

long long mult_mod(long long a,long long b,long long c){
    a %= c;b %= c;
    long long ret = 0,tmp = a;
    while(b){
        if(b&1){
            ret += tmp;
            if(ret > c) ret -= c;
        }
        tmp <<= 1;
        if(tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret;
}

long long pow_mod(long long a,long long n,long long mod){
    long long ret = 1;
    long long temp = a%mod;
    while(n){
        if(n&1) ret = mult_mod(ret,temp,mod);
        temp = mult_mod(temp,temp,mod);
        n >>= 1;
    }
    return ret;
}

bool check(long long a,long long n,long long x,long long t){
    long long ret = pow_mod(a,x,n);
    long long last = ret;
    for(int i = 0;i <= t;i++){
        ret = mult_mod(ret,ret,n);
        if(ret == 1 && last != 1 && last != n-1) return true;
        last = ret;
    }
    if(ret != 1) return true;
    else return false;
}

bool Miller_Rabin(long long n){
    if(n < 2) return false;
    if(n == 2) return true;
    if((n&1) == 0) return false;
    long long x = n-1;
    long long t = 0;
    while((x&1) == 0) {x >>= 1;t++;}
    srand(time(NULL));
    for(int i = 0;i < S;i++){
        long long a = rand()%(n-1) + 1;
        if(check(a,n,x,t)) return false;
    }
    return true;
}

long long factor[100];
int tol;

long long gcd(long long a,long long b){
    long long t;
    while(b){
        t = a;
        a = b;
        b = t%b;
    }
    if(a >= 0) return a;
    else return -a;
}

long long pollard_rho(long long x,long long c){
    long long i = 1,k = 2;
    srand(time(NULL));
    long long x0 = rand()%(x-1)+1;
    long long y = x0;
    while(1){
        i++;
        x0 = (mult_mod(x0,x0,x)+c) % x;
        long long d = gcd(y-x0,x);
        if(d != 1 && d != x) return d;
        if(y == x0) return x;
        if(i == k){y = x0;k += k;}
    }
}

void findfac(long long n,int k){
    if(n == 1) return;
    if(Miller_Rabin(n)){
        factor[tol++] = n;return;
    }
    long long p = n;
    int c = k;
    while(p >= n) p = pollard_rho(p,c--);
    findfac(p,k);
    findfac(n/p,k);
}
const int mod = 1e9+7;
int cals(int n){
    int ans = 1,a = 2;
    while(n) {
        if(n % 2 == 1)
        ans = (ans*a) % mod;
        n /= 2;
        a = (a*a) % mod;
    }
    return ans;
}
int main(){
    int n;scanf("%d",&n);
    printf("%d",cals(n));
}
