#include <bits/stdc++.h>

using namespace std;

int main(){
    int k = 1;
    for(int i = 1;i <= 16;i++){
        k *= 10;
        printf("%d : mod 73:%d;mod 137:%d",k,k%73,k%137);
    }
}
