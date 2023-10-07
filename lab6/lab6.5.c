#include <stdio.h>

void main() {
	int i;
	int n;
	int count;
	int a;


	printf("n = ");
	scanf_s("%d", &n);

	printf("a = ");
	scanf_s("%d", &a);

	i = 1;
	count = 0;
	do{
		if (i % a == 0)
			printf("%d ", i);
		i += 1;
		count = i / a;
	} while (count <= n);
	
}