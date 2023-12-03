#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Бочкарёва Елизавета\n");
	printf("Задача 5\n");

	// Чтение из входного файла

	int a[10];
	int n;
	int i;

	// Входной файл
	FILE* fin = fopen("c:\\Users\\eliza\\Desktop\\in5.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf(fin, "%d", &n);
	
	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]);
	}
	fclose(fin);

	// логирование ввода
	printf("ввели массив a[%d] = ", n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	// Обработка
	// Вычисляем среднее арифметическое 
	int s = 0; // сумма
	for (i = 0; i < n; i++) {
		s += a[i];
	}

	float sa = (float)s / n;

	// логирование обработки
	printf("\nsa = %f\n", sa);
	
	// Обработка
	// Обновляем значения элементов
	for (i = 0; i < n; i++) {
		if (a[i] > sa) {
			a[i] *= 10;
		}
	}
	// логирование вывода
	printf("вывели массив a[%d] = ", n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	// Запись в выходной файл
	// Выходной файл
	FILE* fout;
	fout = fopen("c:\\Users\\eliza\\Desktop\\out5.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	fprintf(fout, "d\n", n);
	
	for (i = 0; i < n; i++) {
			//printf("%d ", a[i]);
			fprintf(fout, "%d ", a[i]);
		} 
		fclose(fout);
	}
