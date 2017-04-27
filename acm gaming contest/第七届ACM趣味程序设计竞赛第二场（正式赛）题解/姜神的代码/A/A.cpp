#include <cstdio>
const int N = 2000 + 10;
int n, m, a[N];
int sum[110][N];
int main() {
	scanf("%d%d", &n, &m);
	for(int j = 1; j <= m; j++) sum[j][0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[a[i]][i] = 1;
		for(int j = 1; j <= m; j++) sum[j][i] += sum[j][i-1];
	}
	int q; scanf("%d", &q);
	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		int res = 0;
		for(int j = 1; j <= m; j++) {
			if(sum[j][r] - sum[j][l-1] > 0) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
