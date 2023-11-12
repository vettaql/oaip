#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements();
void keyboardInput();
void oddsX10();
void chetnXmin1();
void zamenana4();
int menshe10();
int findMin();
int findLastEven();
int findIndexMin();



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
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов <10\n");
		printf("5: x2 для последнего чётного\n");
		printf("6: Сколько чётных левее минимального\n");
		printf("7: Все четные элементы массива умножить на -1\n");
		printf("8: Все элементы массива имеющие значения меньше 4 заменить на 4\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		break;

		case 4:
		{
			int c = menshe10();
			printf("count = %d\n", c);
		}
		break;

		case 5:
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			}
		}
		break;

		case 6:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
				printf("Левее минимального %d четных элементов\n", cnt);
			}
		}
		break;
		
		case 7:
			chetnXmin1();
			break;

		case 8:
			zamenana4();
			break;
		
		}
		

	} while (item != 0);
}

void printElements() {
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void keyboardInput() {
	printf("n = "); 
	scanf_s("%d", &n);
	
	printf("input %d values: ", n); 
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}


int findMin() {
		int min = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
}

int menshe10() {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 10) {
			c++;
		}
	}
	return c;
}

int findLastEven() {
	for (int i = n - 1; i; i--) {
		if (arr[i] % 2 == 0) {
			return i;
		}
	}
	return -1;
}

int findIndexMin() {
	int min = arr[0];
	int indexMin = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			indexMin = i;
		}
	}
	return indexMin;
}
void chetnXmin1() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = arr[i] * (-1);
		}
	}
}
void zamenana4() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) {
			arr[i] = 4;
		}
	}
}
