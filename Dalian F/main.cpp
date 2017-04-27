#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int T, n, sum, ok;
int a[maxn];
bool cmp (int a, int b) {
    return a > b;
}
bool input () {
    ok = 1; sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        sum += a[i];
    }
    sort (a + 1, a + n + 1, cmp);
    return true;
}
int main (void) {
    while (scanf ("%d", &T) != EOF) {
        for (int kase = 1; kase <= T; kase++) {
            input ();
            int left = 0;
            if (sum != n * (n-1)) {
                printf ("F\n");
                continue;
            }
            for (int i = 1; i <= n; i++) {
                int limit = 2 * (n-i) + left;
                //printf ("%d %d\n", limit, a[i]);
                if (limit < a[i]) {
                    ok = 0;
                    break;
                }
                left = limit - a[i];
            }
            if (ok) printf ("T\n");
            else printf ("F\n");
        }
    }
    return 0;
}
