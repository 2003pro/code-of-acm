#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
vector<int> to[maxn];
int T, n, m, a, b;
int ans[2][maxn][maxn];
bool used[2][maxn][maxn];
int check (int u, int a, int b) {
    if (ans[u][a][b]) return ans[u][a][b];
    int &ret = ans[u][a][b];
    if (used[u][a][b]) {
        //printf ("forever%d %d %d: %d\n", u, a, b, ret);
        return 1;
    }
    used[u][a][b] = 1;
    if (a == b) ret = 2;
    else if (u == 0) {
        int sz = to[a].size();
        if (sz == 0) ret =  2;
        else {
            int ok = 0;
            for (int i = 0; i < sz; i++) {
                if (check(1, to[a][i], b) == 1)
                    ok = 1;
            }
            if (ok == 1) ret = 1;
            else ret = 2;

        }
    }
    else {
        int sz = to[b].size();
        if (sz == 0) ret = 1;
        else {
            int ok = 0;
            for (int i = 0; i < sz; i++) {
                if (check(0,a,to[b][i]) == 2)
                    ok = 1;
            }
            if (ok == 1) ret = 2;
            else ret = 1;
        }
    }
    used[u][a][b] = 0;
    //printf ("%d %d %d: %d\n", u, a, b, ret);
    return ret;
}
void init () {
    memset (ans, 0, sizeof (ans));
    memset (used, 0, sizeof (used));
    for (int i = 0; i < maxn; i++)
         to[i].clear();
}
int main (void) {
    scanf ("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf ("%d%d", &n, &m);
        init ();
        for (int i = 1; i <= m; i++) {
            int f, t;
            scanf ("%d%d", &f, &t);
            to[f].push_back (t);
        }
        scanf ("%d%d", &a, &b);
        printf ("Case #%d: ", kase);
        if (check (0, a, b) == 1) printf ("Yes\n");
        else printf ("No\n");
    }
    return 0;
}
