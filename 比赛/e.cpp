#include <bits/stdc++.h>
using namespace std;
const int maxn = 22222;
int f[maxn];
int T, n, k, a, b;
char cmd[3];
int found (int x) {
    if (f[x] == 0) return x;
    else {
        return found(f[x]);
    }
}
bool check (int a, int b) {
    if (found(a) == found(b))
        return true;
    else
        return false;
}
int main (void) {
    scanf ("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        printf ("Case #%d:\n", kase);
        scanf ("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &f[i]);
        }
        for (int i = 1; i <= k; i++) {
            scanf ("%s", cmd);
            if (cmd[0] == 'C') {
                scanf ("%d", &a);
                f[a] = 0;
            }
            else {
                scanf ("%d%d", &a, &b);
                //printf ("a:%d b:%d\n", found(a), found(b));
                if (check (a, b)) printf ("YES\n");
                else printf ("NO\n");
            }
        }
    }
    return 0;
}
