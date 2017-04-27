#include <cstdio>
#include <cstring>
#include <cmath>
const double EPS = 1e-9;
int sign(double x) {
	if(fabs(x) < EPS) return 0;
	return x > 0 ? 1 : -1;
}
int dcmp(double x, double y) {
	return sign(x - y);
}
double calc(double x, char o, double y) {
	if(o == '+') return x + y;
	if(o == '-') return x - y;
	if(o == '*') return x * y;
	if(o == '/') return x / y;
}
char ops[] = "+-*/";
bool can(int a, int b, int c, int d) {
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++) {
				char o1 = ops[i], o2 = ops[j], o3 = ops[k];
				// (ab)(cd)
				if(dcmp(calc(calc(a, o1, b), o2, calc(c, o3, d)), 24.0) == 0) return 1;
				// a((bc)d)
				if(dcmp(calc(a, o1, calc(calc(b, o2, c), o3, d)), 24.0) == 0) return 1;
				// a(b(cd))
				if(dcmp(calc(a, o1, calc(b, o2, calc(c, o3, d))), 24.0) == 0) return 1;
				// ((ab)c)d
				if(dcmp(calc(calc(calc(a, o1, b), o2, c), o3, d), 24.0) == 0) return 1;
				// (a(bc))d
				if(dcmp(calc(calc(a, o1, calc(b, o2, c)), o3, d), 24.0) == 0) return 1;
			}
	return 0;
}
int a[10], idx[10], hash[10];
bool dfs(int x) {
	if(x > 4) {
		if(can(a[idx[1]], a[idx[2]], a[idx[3]], a[idx[4]])) return 1;
		return 0;
	}
	for(int i = 1; i <= 4; i++) if(!hash[i]) {
		hash[i] = 1;
		idx[x] = i;
		if(dfs(x + 1)) return 1;
		hash[i] = 0;
	}
	return 0;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		for(int i = 1; i <= 4; i++) scanf("%d", &a[i]);
		memset(hash, 0, sizeof(hash));
		if(dfs(1)) puts("yes"); else puts("no");
	}
	return 0;
}
