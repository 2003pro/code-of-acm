#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
struct P {
    LL x, y, z;
    bool operator < (const P &a) const {
        if (x == a.x)
            if (y == a.y)
                return z < a.z;
            else
                return y < a.y;
        else
            return x < a.x;
    };
};
set <P> nude;
set <P> moved;
LL ans;
LL X, Y, Z, N;
struct Item {
    int out, in;
};
map<P, Item> cube;
void trans (LL x, LL y, LL z) {
    P u = {x, y, z};
    if (!nude.count (u)) {
        //printf ("build: %lld %lld %lld\n", x, y, z);
        nude.insert (u);
        cube[u].out = 0;
        cube[u].in = 6;
    }
    //printf ("%lld %lld %lld: out%d in%d\n", x, y, z, ++cube[u].out, --cube[u].in);
    cube[u].out++;
    cube[u].in--;
    printf ("%lld %lld %lld: out%d in%d\n", x, y, z, cube[u].out, cube[u].in);
}
void bound (LL x, LL y, LL z) {
    P u = {x, y, z};
    if (!nude.count (u)) {
        nude.insert (u);
        cube[u].out = 0;
        cube[u].in = 6;
    }
    if (x == 0) trans(x, y, z);
    if (x == X - 1) trans (x, y, z);
    if (y == 0) trans (x, y, z);
    if (y == Y - 1) trans (x, y, z);
    if (z == 0) trans (x, y, z);
    if (z == Z - 1) trans (x, y, z);
}
void remove (LL x, LL y, LL z) {
    P u = {x, y, z};
    bound (x, y, z);
    ans -= cube[u].out;
    ans += cube[u].in;
    moved.insert (u);
    for (int i = 0; i < 6; i++) {
        LL nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        P nu = {nx, ny, nz};
        if (nx < 0 || nx >= X || ny < 0 || ny >= Y || nz < 0 || nz >= Z || moved.count(nu))
            continue;
        trans(nx, ny, nz);
    }
}

int main (void) {
    scanf ("%I64d%I64d%I64d%I64d", &X, &Y, &Z, &N);

    ans = (X * Y + Y * Z + X * Z) * 2;
    //puts ("!!!");
    for (int i = 0; i < N; i++) {
        LL x, y, z;
        scanf ("%I64d%I64d%I64d", &x, &y, &z);
        remove (x, y, z);
    }
    printf ("%I64d", ans);
    return 0;
}
