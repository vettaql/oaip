
#include <stdio.h>

long fuct2(int n) {
	if (n == 0) {
		return 1;
	}

	long res = fuct2(n - 1) * n;
	return res;
}

void main() {
	int n = 5;
	long f = fuct2(n);

	printf("%d! = %ld", n, f);
}
