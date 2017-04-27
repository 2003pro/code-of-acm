#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > row;
map<int, vector<int> > col;
vector<int> rv, cv;
set<int> rs, cs;
struct P {
    int x, y;
    bool operator < (const P &b) const {
        if (x == b.x) return y < b.y;
        else return x < b.x;
    }
};
set<P> used;
map<P, char> sign;
map<P, int> rpo;
map<P, int> cpo;
int ans;
void put_in (int x, int y) {
    if (!rs.count(x)) {
        rv.push_back (x);
        rs.insert (x);
    }
    if (!cs.count (x)) {
        cv.push_back (x);
        cs.insert (x);
    }
    row[x].push_back (y);
    col[y].push_back (x);
}
int walk (int x, int y) {
    P u = {x, y};
    if (sign[u] == '>') {
        int nx = x, ny = y;
        P nu = {nx, ny};
        while (used.count (nu)) {
            if (rpo[nu] == row[x].size()-1)
                return 1;
            ny = row[x][rpo[nu] + 1];
            nu.y = ny;
        }
        return 1 + walk (nx, ny);
    }
    if (sign[u] == '<') {
        int nx = x, ny = y;
        P nu = {nx, ny};
        while (used.count (nu)) {
            if (rpo[nu] == 0)
                return 1;
            ny = row[x][rpo[nu] - 1];
            nu.y = ny;
        }
        return 1 + walk (nx, ny);
    }
    if (sign[u] == '^') {
        int nx = x, ny = y;
        P nu = {nx, ny};
        while (used.count (nu)) {
            if (cpo[nu] == 0)
                return 1;
            nx = col[y][cpo[nu] - 1];
            nu.x = nx;
        }
        return 1 + walk ( nx, ny);
    }
    if (sign[u] == 'v') {
        int nx = x, ny = y;
        P nu = {nx, ny};
        while (used.count (nu)) {
            if (cpo[nu] == col[y].size() - 1)
                return 1;
            nx = col[y][cpo[nu] + 1];
            nu.x = nx;
        }
        return 1 + walk ( nx, ny);
    }
}
int n;
int main (void){
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        char s[2];
        scanf ("%d%d%s", &x, &y, s);
        put_in (x, y);
        sign[{x, y}] = s[0];
    }
    sort (rv.begin (), rv.end ());
    sort (cv.begin (), cv.end ());
    for (int i = 0; i < rv.size(); i++) {
        int r = rv[i];
        sort (row[i].begin(), row[i].end());
        for (int j = 0; j < row[r].size(); j++) {
            int c = row[r][j];
            rpo[{r,c}] = j;
        }
    }
    for (int i = 0; i < cv.size(); i++) {
        int c = cv[i];
        sort (col[i].begin(), col[i].end());
        for (int j = 0; j < col[c].size(); j++) {
            int r = col[c][j];
            cpo[{r,c}] = j;
        }
    }
    for (int i = 0; i < rv.size(); i++) {
        int r = rv[i];
        for (int j = 0; j < row[r].size(); j++) {
            int c = row[r][j];
            used.clear();
            used.insert ({r,c});
            ans = max (ans, walk (r, c));
        }
    }
    printf ("%d", ans);
    return 0;
}
