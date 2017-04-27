#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int cur = 0,tot = 0,b[9];
bool ok;
string s[400];

void solve1(){
    s[tot] = "";
    for(int i=0;i<9;i++){
        s[tot] += itoa(b[i]);
        s[tot] += " ";
    }
}

void search1(int cur){
    if(cur == 9) {
        tot++;
        solve1();
        return;
    }
    else{
        for(int i = 0;i < 9;i++){
            ok = true;
            b[cur] = i;
            for(int j = 0;j < cur;j++){
                if(b[cur] == b[j]||cur - b[cur] == j - b[j]||cur + b[cur] == j + b[j]){
						ok=false;
						break;
					}
            }
            if(ok) search1(cur + 1);
        }
    }
}


void print1(){
    printf("%d\n",tot);
    for(int i = 1;i <= tot;i++){
        cout<<s[i]<<endl;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    search1(0);
    print1();
    return 0;
}
