#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#include <ctype.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toupper(s[i]);
	}
	printf("\nОбработанная строка: %s\n", s);
	{
		int x;
		scanf("%d", &x);
	}
}
