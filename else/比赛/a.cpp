#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
int T, n, k, ans;
int a[maxn];
int f[maxn];
int found (int x) {
    if (f[x] == x) return x;
    else {
        f[x] = found(f[x]);
        return f[x];
    }
}
set<int> used;
int main (void) {
    scanf ("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        used.clear();
        scanf ("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &a[i]);
            f[i] = i;
        }
        sort (a + 1, a + n + 1);
        for (int i = 2; i <= n; i++) {
            if (a[i] - a[i-1] <= k) {
                f[i] = found(i-1);
            }
        }
        for (int i = 1; i <= n; i++) {
            //printf ("%d%d\n", a[i], found(i));
            if (!used.count(found(i)))
                used.insert (found(i));
        }
        printf ("Case #%d: %d\n", kase, used.size());
    }
    return 0;
}
