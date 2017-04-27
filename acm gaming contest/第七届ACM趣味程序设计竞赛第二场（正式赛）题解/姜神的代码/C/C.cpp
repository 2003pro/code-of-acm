#include <cstdio>
#include <algorithm>
int n, m;
int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		long long res = 0, sum = 0;
		for(int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			if(x > res) res = x;
			sum += x;
		}
		res = std::max(res, (sum + m - 1) / m);
		printf("%lld\n", res);
	}
	return 0;
}
