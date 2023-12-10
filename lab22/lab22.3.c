#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Введите символ: ");
    int ch;
    scanf(" %c", &ch);

    for (int c = ch; c >= ch - 29; c--) {
        printf("'%c' (%d) \n", c, c);
    }

    return 0;
}