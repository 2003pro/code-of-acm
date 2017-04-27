#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100003;
string s;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll x[N],y[N];
ll d[N];
int main()
{
    cin>>s;int tx = 0,ty = 0;
    int n = s.size();
    for(int i = 0;i < n;i++){
        if(s[i] == 'U')tx += dx[0],ty += dy[0];
        else if(s[i] == 'R')tx += dx[1],ty += dy[1];
        else if(s[i] == 'D')tx += dx[2],ty += dy[2];
        else if(s[i] == 'L')tx += dx[3],ty += dy[3];
        x[i] = tx,y[i] = ty,d[i] = tx*tx + ty*ty;
    }
    for(int i = )
    return 0;
}
