#include <bits/stdc++.h>
const int N = 60;
int c[N][N];

void makec(){
    for(int i = 0;i < N;i++) c[i][0] = 1;
    for(int i = 1;i < N;i++){
        for(int j = 1;j <= min(i,N - 1);j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}
void solve(int m,int k){

}
int main(){
    makec();
    for(int i = 1;i <= 10;i++){
        for(int j = 1;j <= 10;j++){
            solve(i,j);
        }
    }
}
