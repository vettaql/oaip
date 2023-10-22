#include <stdio.h>

#include <Windows.h>

void Task1() {
	int m;
	int n;
	int i;
	int j;
	scanf_s("%d", &n);
	scanf_s("%d", &m);

	i = 1;
	do {
		j = 1;
		do {
			printf("%d ", i * 10 + j);
			j += 1;
	} while (j <= m);
	printf("\n");
	i += 1;
	} while (i <= n);
}

void Task2() {
	int i;
    int j;

	i = 1;
	do {
		j = 1;
		do {
			printf("%2d ", j * i);
			j += 1;
		} while (j <= 10);
	    printf("\n");
		i += 1;
	} while (i <= 10);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int d;
	do {
		printf("\n");
		printf("\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Задача 1 (i * 10 + j)\n");
		printf("2: Задача 2 (Таблица Пифагора)\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		scanf_s("%d", &d);
		switch (d) {
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		}
	} while (d != 0);
}