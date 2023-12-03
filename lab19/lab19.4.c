#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int* pa;  
int n; 

void Load() {
	// Открытие входного файла
	FILE* fin = fopen("c:\\Users\\eliza\\Desktop\\in4.txt", "rt");
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
	// Вычисление максимального дохода
	int maxi = pa[0];
	for (int i = 0; i < n; i++) {
		if (maxi < pa[i]) {
			maxi = pa[i];
		}
	}
	// Выяснение, сколько элементов высокий доход
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] >= (2 * maxi) / 3) {
			m++;
		}
	}
	// Открытие выходного файла
	FILE* fout = fopen("c:\\Users\\eliza\\Desktop\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	// Сохранение элементов высоких доходов
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] >= (2 * maxi) / 3)  {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	// Закрытие файла
	fclose(fout);
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Hello! It is Task4!\n");

	Load();
	SaveResult();

	free(pa);
}
