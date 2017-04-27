#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL L, R;
int main (void) {
    while (scanf ("%lld%lld", &L, &R) != EOF) {
        if (R <= 1) printf ("0\n");
        else if (R == 2) printf ("1\n");
        else if (L <= 1) {
            LL ans = (R + 1) / 2;
            if (ans < 2) ans = 2;
            printf ("%lld\n", ans);
        }
        else {
            LL ans = (R - L + 2) / 2;
            if (ans < 2) ans = 2;
            printf ("%lld\n", ans);
        }
    }
    return 0;
}
