#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL maxn = 3e5+10;
LL tree[maxn];
LL a[maxn];
vector<LL> son[maxn];
LL f[maxn];
vector<LL> exist;
set<LL> s;
map<LL, LL> id;
LL T, n, k, root;
LL ans;
LL read(LL k) {
  LL sum = 0;
  for (; k; k^=k&-k) sum+=tree[k];
  return sum;
}
void update(LL k, LL v) {
  for (; k<=maxn; k+=k&-k) tree[k]+=v;
}

void putin (LL x) {
    if (!s.count(x)) {
        s.insert (x);
        exist.push_back(x);
    }
}
void init () {
    exist.clear();
    s.clear();
    id.clear();
    memset (f, 0, sizeof (f));
    ans = 0;
}
void input () {
    scanf ("%I64d%I64d", &n, &k);
    for (int i = 1; i <= n; i++) {
        son[i].clear();
        scanf ("%I64d", &a[i]);
        putin (a[i]);
        if (a[i] != 0) putin (k/a[i]);
        else putin (k+1);
    }
    for (int i = 1; i <= n - 1; i++) {
        LL u, v;
        scanf ("%I64d%I64d", &u, &v);
        son[u].push_back(v);
        f[v] = u;
    }
    sort (exist.begin(), exist.end());
    int sz = exist.size();
    for (int i = 0; i < sz; i++) {
        //printf("in:%lld\n", exist[i]);
        id[exist[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == 0) {
            root = i;
            break;
        }
    }
}

void dfs (int r) {
    int sz = son[r].size();
    if (a[r] != 0) {
        ans += read (id[k/a[r]]);
        //printf ("%d : %lld\n", r, read(id[k/a[r]]));
    }
    else {
        ans += read (id[k+1]);
        //printf ("%d : %lld\n", r, read(k+1));
    }

    update (id[a[r]], 1);
    for (int i = 0; i < sz; i++) {
        dfs (son[r][i]);
    }
    update (id[a[r]], -1);
}
int main (void) {
    scanf ("%I64d", &T);
    for (int kase = 1; kase <= T; kase++) {
        init ();
        input ();
        dfs (root);
        printf ("%I64d\n", ans);
    }
    return 0;
}
