#include<bits/stdc++.h>
using namespace std;
const int maxn = 1111;
bool light[maxn];
bool lightn[maxn];
int sw[maxn];
int T, n, k, tmp, ans, cnt;
int main (void) {
    scanf ("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        ans = 0;
        scanf ("%d%d", &n, &k);
        memset (light, 0, sizeof(light));
        for (int i = 1; i <= k; i++) {
            scanf ("%d", &sw[i]);
        }
        sort (sw + 1, sw + k + 1);
        for (int i = 1; i <= k; i++) {
            tmp = sw[i];
            memcpy (lightn, light, sizeof (light));
            cnt = 0;
            for (int j = 1; j * tmp <= n; j++) {
                if (light[j*tmp]) {
                    lightn[j*tmp] = false;
                    cnt--;
                }
                else {
                    lightn[j*tmp] = true;
                    cnt++;
                }
            }
            if (cnt > 0) {
                memcpy(light, lightn, sizeof(light));
            }
        }
        for (int i = 1; i <= n; i++) {
            if (light[i]) ans++;
        }
        printf ("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
