// вывести степени числа 7 от 0 до n
#include <stdio.h>
void main() {
	int i;
	int stepen;
	int n;
	int count;

	printf("n = ");
	scanf_s("%d", &n);

	stepen = 1;
	i = 0;

	do {
		printf("7^%d = %d\n", i, stepen);
		stepen *= 7;
		i += 1;
		count = i / 7^i;

	} while (count <= n);
}