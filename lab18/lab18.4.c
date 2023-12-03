#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Бочкарёва Елизавета\n");
	printf("Задача 4\n");

	// Чтение из входного файла

	// Числа, читаемые из входного файла
	int a, b, c, d, e;
	// Произведение, выводимое в выходной файл
	int s;

	// Входной файл
	FILE* fin = fopen("c:\\Users\\eliza\\Desktop\\in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	fclose(fin);
	// логирование ввода
	printf("ввели: %d, %d, %d, %d, %d\n", a, b, c, d, e);

	// Обработка
	s = a + b + c + d + e;

	// логирование вывода
	printf("s =  %d\n", s);

	// Запись в выходной файл

	// Выходной файл
	FILE* fout;
	fout = fopen("c:\\Users\\eliza\\Desktop\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	fprintf(fout, "%d", s);
	fclose(fout);

}