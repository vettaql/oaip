#include <stdio.h>

void main() {
	int i;
	int n;
	int count;


	printf("n = ");
	scanf_s("%d", &n);


	i = 1;
	count = 0;
	do{
		if (i % 2 == 0)
			printf("%d ", i);
		i += 1;
		count = i / 2;
	} while (count <= n);
	
}
