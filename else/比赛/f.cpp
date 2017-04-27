#include<bits/stdc++.h>
using namespace std;
const int maxn = 111111;
vector<int> A;
struct Inter {
    int l, r;
};
struct Dragon {
    int A, B, C;
};
Dragon dragons[maxn];
vector<Inter> interv1;
vector<Inter> interv2;
int T, n, ans;
set<int> sword;
bool cmp (Inter a, Inter b) {
    if (a.r == b.r)
        return a.l > b.l;
    else
        return a.r < b.r;
}
int main (void) {
    scanf ("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        interv1.clear(); interv2.clear(); A.clear();
        ans= 0;
        sword.clear();
        scanf ("%d", &n);
        for (int i = 1;i <= n; i++) {
            scanf ("%d%d%d", &dragons[i].A, &dragons[i].B, &dragons[i].C);

            if (!sword.count(dragons[i].A)) {
                sword.insert(dragons[i].A);
                A.push_back(dragons[i].A);
            }
        }
        ans = sword.size();
        //printf ("ans%d\n", ans);
        sort (A.begin(), A.end());
        for (int i = 1; i <= n; i++) {
            int posB = lower_bound (A.begin(), A.end(), dragons[i].B) - A.begin();
            int posC = upper_bound (A.begin(), A.end(), dragons[i].C) - A.begin();
            //printf ("%d %d %d\n", posB, posC, dragons[i].A);
            if (posC - posB == 0 || (posC - posB == 1 && A[posB] == dragons[i].A)) {
                interv1.push_back({dragons[i].B, dragons[i].C});
            }
        }
        int sz  = interv1.size();
        sort (interv1.begin(), interv1.end(), cmp);
        if (sz > 0) interv2.push_back(interv1[0]);
        for (int i = 1; i < sz; i++) {
            if(interv1[i].l > interv1[i - 1].l) {
                interv2.push_back(interv1[i]);
            }
        }

        sz = interv2.size();
        //printf ("interv2.sz:%d\n", sz);
        int last = 0;
        for (int i = 0; i < sz; i++) {
            //printf ("l:%d r:%d\n", interv2[i].l, interv2[i].r);
            if (interv2[i].l > last) {
                ans++;
                last = interv2[i].r;
            }
        }
        printf ("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
