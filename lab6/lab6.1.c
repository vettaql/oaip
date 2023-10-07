#include <stdio.h>

void main() {
	int i;
	int n;

	printf("n = ");
	scanf_s("%d", &n);

	i = 1;
	do {
		printf("%d ", i);
		i += 1;
	} while (i <= n);
} 