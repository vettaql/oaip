#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char name[12];
	printf("Введите ваше имя:");
	fgets(name, 11, stdin);
	printf("Приветствую тебя, %s\n", name);
	{
		int x;
		scanf("'%d", &x);
	}
}