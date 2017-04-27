#include <cstdio>
#include <algorithm>

long long sum;
int mx;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		int f;
		scanf("%d", &f);
		sum += f;
		mx = std::max(mx, f);
	}
	printf("%lld\n", std::max((sum + M - 1) / M, 1ll * mx));
	return 0;
}
