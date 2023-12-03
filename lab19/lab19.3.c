#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int* pa;  
int n; 

void Load() {
	// Открытие входного файла
	FILE* fin = fopen("c:\\Users\\eliza\\Desktop\\in3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	// Загрузка массива из входного файла
	fscanf(fin, "%d", &n);
	// Выделение памяти под динамический массив
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	// Закрытие входного файла
	fclose(fin);
}
void SaveResult() {
	// Вычисление среднего арифметического
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	// Выяснение, сколько элементов меньше ср арифметического и больше 0
	int m = 0;
	for (int i = 0; i < n; i++) {
		if ((pa[i] < sa) and (pa[i] > 0)) {
			m++;
		}
	}
	// Открытие выходного файла
	FILE* fout = fopen("c:\\Users\\eliza\\Desktop\\out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	// Сохранение элементов больших 0 меньших ср арифм
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if ((pa[i] < sa) and (pa[i] > 0))   {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	// Закрытие файла
	fclose(fout);
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Hello! It is Task3!\n");

	Load();
	SaveResult();

	free(pa);
}
