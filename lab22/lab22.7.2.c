#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#include <ctype.h>

int toUpperAll(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'a' && c <= 'п')
		new_c = 'A' + (c - 'a');
	if (c >= 'p' && c <= 'я')
		new_c = 'Р' + (c - 'p');
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toUpperAll(s[i]);
	}
	printf("\nОбработанная строка: %s\n", s);
	{
		int x;
		scanf("%d", &x);
	}
}
