#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
	double a = 0.0,b = 0.8;
	double h,ds,s = -6,sum;
	double eps = 1E-8;
	int i,n = 1;
	scanf("%lf",sum);
	while(fabs(sum - s) > eps) {
		++n;
		h = (b - a)/(2 * n);
		ds = 0.0;
		sum = s;
		for(i = 1; i <= 2 * n - 1; ++i)
			ds += 2.0 * exp(-0.5*(a + 2 * (i - 1) * h)) + exp(-0.5*(a + 2 * i * h));
		s = (b - a)/(3 * n) * (exp(-0.5*a) - exp(-0.5*b) + ds) / 2.0;
	}
	printf("s = %lf\n",s);
	return 0;
}
