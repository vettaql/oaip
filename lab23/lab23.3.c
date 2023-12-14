#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Бочкарёва Елизавета\n");
	printf("ЛР23 Задача 1\n");
	char line[1000];

	// Входной файл
	FILE* fin = fopen("c:\\Users\\eliza\\Desktop\\intext3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("c:\\Users\\eliza\\Desktop\\outtext3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	// в цикле для всех строк
	while (fgets(line, sizeof(line), fin) != NULL) {
		int has_letter = 0; // флаг, указывающий наличие буквы в строке

		// Проверка каждого символа в строке
		for (int i = 0; line[i] != '\0'; i++) {
			if (isalpha(line[i])) {
				has_letter = 1;
				break;
			}
		}

		// Добавление символа '#' в конец строки при наличии буквы
		if (has_letter) {
			fprintf(fout, "%s#", line);
		}
		else {
			fprintf(fout, "%s", line);
		}
	}


			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
	
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 1 FINISH\n");
}
