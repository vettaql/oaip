#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Бочкарёва Елизавета\n");
	printf("Задача 1\n");

	// Числа, читаемые из входного файла
	int a, b, c;
	// Произведение, выводимое в выходной файл
	int p;

	scanf("%d%d%d", &a, &b, &c);
	printf("ввели: %d, %d, %d\n", a, b, c);
	// Обработка
	p = a * b * c;
	printf("p =  %d\n", p);
}