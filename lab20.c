#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


#define MAX_N 8
#define MAX_M 10


int arr[MAX_N][MAX_M];
int n = 0;
int m = 0;


void printElements();
void fillIx10();
void fillZero();
void randFill0_9();
void oddsX10();
void ifKratno10X10();
void fileInput();
void fileOutput();
void deleteRow(int delRow);
void duplicateColumn(int colIndex);
void replaceWithMax();


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Заполнить значениями i * 10 + j\n");
		printf("2: Заполнить нулями\n");
		printf("3: Заполнить случайными значениями\n");
		printf("4: Все нечетные увеличить в 10 раз\n");
		printf("5: Все кратные 10 уменьшить в 10 раз\n");
		printf("6: Ввести массив с клавиатуры\n");
		printf("7: Ввести массив из файла\n");
		printf("8: Сохранить результат в файл\n");
		printf("9: Удалить заданную строку  из массива\n");
		printf("10: Продублировать заданный столбец массива\n");
		printf("11: (Вариант А5) В массиве все четные элементы, стоящие снизу от максимального элемента массива, заменить на максимальный элемент столбца, в котором они расположены\n");
		printf("\n");
		printf("-1: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			fillIx10();
			break;

		case 2:
			fillZero();
			break;

		case 3:
			randFill0_9();
			break;

		case 4:
			oddsX10();
			break;

		case 5:
			ifKratno10X10();
			break;

		case 6:
			keyboardInput();
			break;

		case 7:
			fileInput();
			break;

		case 8:
			fileOutput();
			break;

		case 9: {
			printf("Индекс удаляемого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteRow(index);
		} break;

		case 10: {
			printf("Столбец, который нужно вставить = ");
			int Index;
			scanf("%d", &Index);
			duplicateColumn(Index);
		} break;

		case 11:
			replaceWithMax();
			break;
		}
	} while (item != -1);
}


void printElements() {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void fillIx10() {
	printf("!!!! fillIx10() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}


void fillZero() {
	printf("!!!! fillZero() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}

void randFill0_9() {
	printf("!!!! randFill0_9() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void oddsX10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] % 2 == 1) {
				arr[i][j] = arr[i][j] * 10;
			}
		}
	}
}

void ifKratno10X10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] = arr[i][j] * 10;
			}
		}
	}
}

void keyboardInput() {
	printf("Введите количество строк: ");
	scanf("%d", &n);
	printf("Введите количество столбцов: ");
	scanf("%d", &m);

	printf("Введите значения:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}

void fileInput() {
	FILE* fin = fopen("c:\\Users\\eliza\\Desktop\\in20.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
	}

	fclose(fin);
}

void fileOutput() {
	// Выходной файл
	FILE* fout = fopen("c:\\Users\\eliza\\Desktop\\out20.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}

	fclose(fout);
}

void deleteRow(int delRow) {
	printf("!!!! deleteRow(%d) !!!!\n", delRow);
	for (int i = delRow; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}

void duplicateColumn(int colIndex) {
	if (m < MAX_M) {
		for (int i = 0; i < n; i++) {
			arr[i][m] = arr[i][colIndex];;
		}
		m++;
	}

}

void replaceWithMax() {
	int maxElement = arr[0][0]; // Предполагаем, что первый элемент является максимальным

	// Находим максимальный элемент в массиве
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > maxElement) {
				maxElement = arr[i][j];
			}
		}
	}

	// Заменяем четные элементы, стоящие снизу от максимального элемента
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 0 && arr[i][j] < maxElement) {
				arr[i][j] = maxElement;
			}
		}
	}
}
