#include <bits/stdc++.h>

using namespace std;
char s[1003][1003];
int r,c,cnt = 0;

typedef pair<int,int> P;
stack <P> st;
int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};

void test(int x,int y){
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i],ny = y + dy[i];
        if(nx >= 0 && nx <= r-1 && ny >= 0 && ny <= c-1){
            if(s[nx][ny] == '-') {cnt++;break;}
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&r,&c);
    for(int i = 0;i < r;i++) scanf("%s",s[i]);
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            if(s[i][j] == '+') {
                P te;
                te.first = i;te.second = j;
                st.push(te);
            }
        }
    }
    while(!st.empty()){
        P tem = st.top();
        test(tem.first,tem.second);
        st.pop();
    }
    printf("%d\n",cnt);
    return 0;
}
