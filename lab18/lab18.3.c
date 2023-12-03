#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Бочкарёва Елизавета\n");
	printf("Задача 3\n");

	// Числа, читаемые из входного файла
	int a, b, c, d, e;
	// Произведение, выводимое в выходной файл
	int s;

	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("ввели: %d, %d, %d, %d, %d\n", a, b, c, d, e);
	// Обработка
	s = a + b + c + d + e;
	printf("s =  %d\n", s);
}
