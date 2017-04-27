#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 11111;
const int maxm = 111;
char mp[maxm][maxn];
int west[maxn], east[maxn];
int ans, ansv = 1e8;
int main (void) {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf ("%s", mp[i]+1);
    }
    west[0] = 0; east[n+1] = 0;
    for (int i = 1; i <= n; i++) {
        west[i] = west[i-1];
        for (int j = 1; j <= m; j++) {
            if (mp[j][i] == 'E')
                west[i]++;
        }
    }
    for (int i = n; i >= 1; i--) {
        east[i] = east[i+1];
        for (int j = 1; j <= m; j++) {
            if (mp[j][i] == 'W')
                east[i]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (west[i] + east[i+1] < ansv) {
            ansv = west[i] + east[i+1];
            ans = i;
        }
    }
    printf ("%d %d\n", ans, ans + 1);
    return 0;
}
