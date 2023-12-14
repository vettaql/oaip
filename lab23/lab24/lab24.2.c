
#include <stdio.h>


void rec1(int n) {
	printf(" %d", n);
	if (n > 1) {
		rec1(n - 2);
	}
}

void rec2(int n) {
	if (n > 1) {
		rec2(n - 3);
	}
	printf(" %d", n);
}

void rec3(int n) {
	printf(" %d", n);
	if (n > 1) {
		rec3(n - 4);
	}
	printf(" %d", n);
}

void main() {
	rec1(11);
	printf(" rec1 FINISH\n");

	rec2(11);
	printf(" rec2 FINISH\n");

	rec3(11);
	printf(" rec3 FINISH\n");
}