#include <cstdio>
#include <cstring>
#include <algorithm>
int n, s;
int a[110], b[110];
bool getSmall(int s) {
	memset(a, 0, sizeof(a));
	a[1] = 1; s--;
	if(s < 0) return 0;
	for(int i = n; i > 1; i--) {
		if(s > 9) {
			a[i] = 9;
			s -= 9;
		}
		else {
			a[i] = s;
			s = 0;
		}
	}
	a[1] += s;
	return 1;
}
bool getLarge(int s) {
	memset(b, 0, sizeof(b));
	b[1] = std::max(1, std::min(s, 9)); s -= b[1];
	if(s < 0) return 0;
	for(int i = 2; i <= n; i++) {
		if(s > 9) {
			b[i] = 9;
			s -= 9;
		}
		else {
			b[i] = s;
			s = 0;
		}
	}
	return s == 0;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &s);
		if(s == 0) {
			if(n == 1) puts("0 0");
			else puts("-1 -1");
		}
		else if(getSmall(s) && getLarge(s)) {
			for(int i = 1; i <= n; i++) printf("%d", a[i]); putchar(' ');
			for(int i = 1; i <= n; i++) printf("%d", b[i]); puts("");
		}
		else puts("-1 -1");
	}
	return 0;
}
