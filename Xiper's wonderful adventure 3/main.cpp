#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int N = 362880;
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int fac[] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};
struct node {
    int a[9];
    int step;
}eit[N + 1];
struct node st,et;
int vis[N+1];
int dis[N+1];

bool canMove(int x,int y){
    return x >=0&&x < 3&&y >=0&&y < 3;
}

int m2hash(struct node s){
    int key = 0;
    for (int i = 0; i < 9; i++) {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++) if (s.a[i] > s.a[j]) cnt++;
        key += fac[i] * cnt;
    }
    return key;
}

void bfs(){
    memset(vis,0,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    queue<node> P;
    int sa = m2hash(et);
    dis[sa] = 0;
    eit[sa] = et;
    vis[sa] = 1;
    P.push(et);
    int z = 0;
    while(!P.empty()){
        struct node t = P.front(); P.pop();
        struct node nxt;
        for(z = 0;z < 9;z++){
            if(t.a[z] == 0) break;
        }
        int x = z / 3;
        int y = z % 3;
        for(int i = 0;i <4;i++){
            int nx = x + dx[i];
            int ny = y +dy[i];
            int nz = nx*3 + ny;
            if(canMove(nx,ny)) {
                nxt = t;
                nxt.a[nz] = 0;
                nxt.a[z] = t.a[nz];
                nxt.step = t.step + 1;
                if(vis[m2hash(nxt)] == 0){
                    P.push(nxt);
                    eit[m2hash(nxt)] = nxt;
                    dis[m2hash(nxt)] = nxt.step;
                    vis[m2hash(nxt)] = 1;
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < 8;i++) et.a[i] = i + 1; et.a[8] = 0;
    et.step = 0;
    bfs();
    while(T--){
        int j = 0;
        char str;
        while(j < 9){
            str = getchar();
            if(str == 'x') {st.a[j] = 0;j++;}
            else if(str >='1' && str <='8') {st.a[j] = str - '0';j++;}
        }
        printf("%d\n",dis[m2hash(st)]);
    }
    return 0;
}
